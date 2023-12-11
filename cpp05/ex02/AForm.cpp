/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:51:23 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 17:16:20 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int executeGrade) : m_name(name), m_signed(false), m_signGrade(signGrade), m_executeGrade(executeGrade){
	checkGrade(signGrade);
	checkGrade(executeGrade);
}

AForm::AForm(const AForm& copy) : m_name(copy.m_name), m_signed(copy.m_signed), m_signGrade(copy.m_signGrade), m_executeGrade(copy.m_executeGrade) {
	
}

AForm& AForm::operator=(const AForm& copy) {
	m_signed = copy.m_signed;
	return *this;
}

AForm::~AForm() {
	
}

const std::string& AForm::getName(void) const {
	return m_name;
}

bool	AForm::isSigned(void) const {
	return m_signed;
}

void	AForm::beSigned(const Bureaucrat& b) {
	if (m_signed) {
		return;
	}
	if (b.getGrade() > m_signGrade) {
		throw GradeTooLowException();
	}
	m_signed = true;
}

int AForm::getSignGrade(void) const {
	return m_signGrade;
}

int AForm::getExecGrade(void) const {
	return m_executeGrade;
}

void	AForm::checkGrade(int grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

void AForm::execute(Bureaucrat const & executor) const {
	if (isSigned()) {
		if (executor.getGrade() <= getExecGrade()) {
			formAction(); // Implement in child form classes
		} else {
			throw Bureaucrat::GradeTooLowException();
		}
	} else {
		// std::cout << YELLOW << "Failed to execute form " << getName() << ", because it's not signed" << RESET << std::endl;
		throw FormNotSignedException();
	}
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "AForm signing grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "AForm signing grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "AForm not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "\n--------------------" << std::endl;
	os << "Form name: " << form.getName() << std::endl;
	os << "Form is Signed: " << (form.isSigned() ? "true" : "false") << std::endl;
	os << "Form signing grade: " << form.getSignGrade() << std::endl;
	os << "Form executing grade: " << form.getExecGrade() << std::endl;
	os << "--------------------" << std::endl;
	return os;
}