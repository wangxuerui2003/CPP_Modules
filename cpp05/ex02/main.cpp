/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:46:49 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/27 13:29:19 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include "colors.h"

void	test0(std::string& shrubberyTarget) {
	std::cout << GREEN << "TEST 0: ShrubberyCreationForm test" << RESET << std::endl;

	// Basic test
	{
		Bureaucrat b("b", 100);
		AForm *tree = new ShrubberyCreationForm(shrubberyTarget);
		std::cout << *tree;
		b.signForm(*tree);
		b.executeForm(*tree);
		std::cout << *tree;

		delete tree;
	}
	// Sign grade too low
	{
		Bureaucrat b("b", 146);
		AForm *tree = new ShrubberyCreationForm("signtoolow");
		b.signForm(*tree);
		b.executeForm(*tree);

		delete tree;
	}
	// Exec grade too low
	{
		Bureaucrat b("b", 138);
		AForm *tree = new ShrubberyCreationForm("exectoolow");
		b.signForm(*tree);
		b.executeForm(*tree);

		delete tree;
	}
}

void test1() {
	std::cout << GREEN << "\nTEST 1: RobotomyRequestForm test" << RESET << std::endl;

	srand(time(NULL)); // Reset the random seed in the system

	// Basic Test
	{
		Bureaucrat b("b", 40);
		AForm *f = new RobotomyRequestForm("rob");
		std::cout << *f;
		b.signForm(*f);
		b.executeForm(*f);
		std::cout << *f;

		delete f;
	}

	// Test the randomness
	for (int i = 0; i < 4; ++i)
	{
		Bureaucrat b("b", 40);
		AForm *f = new RobotomyRequestForm("rob");
		b.signForm(*f);
		b.executeForm(*f);

		delete f;
	}
	// Sign grade too low
	{
		Bureaucrat b("b", 73);
		AForm *f = new RobotomyRequestForm("signtoolow");
		b.signForm(*f);
		b.executeForm(*f);

		delete f;
	}
	// Exec grade too low
	{
		Bureaucrat b("b", 46);
		AForm *f = new RobotomyRequestForm("exectoolow");
		b.signForm(*f);
		b.executeForm(*f);

		delete f;
	}
}

void test2() {
	std::cout << GREEN << "\nTEST 2: PresidentialPardonForm test" << RESET << std::endl;

	// Basic test
	{
		Bureaucrat b("b", 5);
		AForm *f = new PresidentialPardonForm("pres");
		std::cout << *f;
		b.signForm(*f);
		b.executeForm(*f);
		std::cout << *f;

		delete f;
	}
	// Sign grade too low
	{
		Bureaucrat b("b", 26);
		AForm *f = new PresidentialPardonForm("signtoolow");
		b.signForm(*f);
		b.executeForm(*f);

		delete f;
	}
	// Exec grade too low
	{
		Bureaucrat b("b", 6);
		AForm *f = new PresidentialPardonForm("exectoolow");
		b.signForm(*f);
		b.executeForm(*f);

		delete f;
	}
}

int main(int ac, char **av) {
	std::string shrubberyTarget;
	if (ac == 1) {
		shrubberyTarget = "home";
	} else {
		shrubberyTarget = av[1];
	}
	test0(shrubberyTarget);
	test1();
	test2();

	std::cout << MAGENTA << std::endl;
	system("leaks -q aform");
	std::cout << RESET << std::endl;
}