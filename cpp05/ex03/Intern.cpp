/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:59:30 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/26 19:48:17 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern& copy) {
	*this = copy;
}

Intern&	Intern::operator=(const Intern& copy) {
	(void)copy;
	return *this;
}

Intern::~Intern() {
	
}

AForm	*Intern::makeForm(std::string formName, std::string target) {
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	std::cout << "Intern creates " << formName << std::endl;
	for (int i = 0; i < 3; ++i) {
		if (formName == names[i]) {
			switch (i) {
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
			}
		}
	}
	std::cout << RED << "Form name \"" << formName << "\" doesn't exist!" << RESET << std::endl;
	return NULL;
}