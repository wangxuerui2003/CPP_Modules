/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:46:49 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/26 19:50:26 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include "colors.h"

void	test0(void) {
	std::cout << GREEN << "TEST 0: ShrubberyCreationForm test" << RESET << std::endl;

	// Basic test
	{
		Intern	intern;
		Bureaucrat b("b", 100);
		AForm *form = intern.makeForm("shrubbery creation", "home");
		if (form != NULL) {
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
		}
	}
	// Form name doesn't exist
	{
		Intern	intern;
		Bureaucrat b("b", 100);
		AForm *form = intern.makeForm("shrubbery destroy", "home");
		if (form != NULL) {
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
		}
	}
}

void test1() {
	std::cout << GREEN << "\nTEST 1: RobotomyRequestForm test" << RESET << std::endl;

	srand(time(NULL)); // Reset the random seed in the system

	// Basic test
	{
		Intern	intern;
		Bureaucrat b("b", 45);
		AForm *form = intern.makeForm("robotomy request", "rob");
		if (form != NULL) {
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
		}
	}
	// Form name doesn't exist
	{
		Intern	intern;
		Bureaucrat b("b", 45);
		AForm *form = intern.makeForm("robotomy response", "rob");
		if (form != NULL) {
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
		}
	}
}

void test2() {
	std::cout << GREEN << "\nTEST 2: PresidentialPardonForm test" << RESET << std::endl;

	// Basic test
	{
		Intern	intern;
		Bureaucrat b("b", 5);
		AForm *form = intern.makeForm("presidential pardon", "pres");
		if (form != NULL) {
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
		}
	}
	// Form name doesn't exist
	{
		Intern	intern;
		Bureaucrat b("b", 5);
		AForm *form = intern.makeForm("presidential parking", "pres");
		if (form != NULL) {
			b.signForm(*form);
			b.executeForm(*form);
		}
		delete form;
	}
}

int main(void) {
	test0();
	test1();
	test2();

	std::cout << MAGENTA << std::endl;
	system("leaks -q intern");
	std::cout << RESET << std::endl;
}