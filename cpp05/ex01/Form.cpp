/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:51:23 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/27 13:20:38 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int signGrade, int executeGrade) : m_name(name), m_signed(false), m_signGrade(signGrade), m_executeGrade(executeGrade){
	checkGrade(signGrade);
	checkGrade(executeGrade);
}

Form::Form(const Form& copy) : m_name(copy.m_name), m_signed(copy.m_signed), m_signGrade(copy.m_signGrade), m_executeGrade(copy.m_executeGrade) {
	
}

Form& Form::operator=(const Form& copy) {
	m_signed = copy.m_signed;
	return *this;
}

Form::~Form() {
	
}

const std::string& Form::getName(void) const {
	return m_name;
}

bool	Form::isSigned(void) const {
	return m_signed;
}

int Form::getSignGrade(void) const {
	return m_signGrade;
}

int Form::getExecGrade(void) const {
	return m_executeGrade;
}

void	Form::beSigned(const Bureaucrat& b) {
	if (m_signed) {
		return;
	}
	if (b.getGrade() > m_signGrade) {
		throw GradeTooLowException();
	}
	m_signed = true;
}

void	Form::checkGrade(int grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Form signing grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form signing grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "\n--------------------" << std::endl;
	os << "Form name: " << form.getName() << std::endl;
	os << "Form is Signed: " << (form.isSigned() ? "true" : "false") << std::endl;
	os << "Form signing grade: " << form.getSignGrade() << std::endl;
	os << "Form executing grade: " << form.getExecGrade() << std::endl;
	os << "--------------------" << std::endl;
	return os;
}