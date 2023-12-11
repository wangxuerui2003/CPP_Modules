/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:34:19 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/27 13:09:32 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name) {
	checkGrade(grade);
	m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) {
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
	checkGrade(copy.getGrade());
	m_grade = copy.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName(void) const {
	return m_name;
}

int Bureaucrat::getGrade(void) const {
	return m_grade;
}

void	Bureaucrat::incGrade(void) {
	checkGrade(m_grade - 1);
	m_grade--;
}

void	Bureaucrat::decGrade(void) {
	checkGrade(m_grade + 1);
	m_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src) {
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << '.' << std::endl;
	return os;
}

void	Bureaucrat::checkGrade(int grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}