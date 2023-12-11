/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:46:49 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/27 13:17:01 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>

void test0(void) {
	std::cout << GREEN << "TEST 0: Basic test" << RESET << std::endl;
	Form f1("form1", 100, 120);
	Bureaucrat b1("john", 90);
	b1.signForm(f1); // can sign

	std::cout << f1;

	Form f2("form2", 80, 120);
	Bureaucrat b2("doe", 90);
	b2.signForm(f2); // grade too low

	b2.signForm(f1); // form already signed by john
}

void test1(void) {
	std::cout << GREEN << "\nTEST 1: Invalid form construction" << RESET << std::endl;
	
	try {
		Form f("form", 151, 120); // grade too low
	} catch (std::exception& e) {
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	try {
		Form f("form", 0, 120); // grade too high
	} catch (std::exception& e) {
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	try {
		Form f("form", 100, 151); // grade too low
	} catch (std::exception& e) {
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	try {
		Form f("form", 100, 0); // grade too high
	} catch (std::exception& e) {
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}

int main(void) {
	test0();
	test1();
	
	std::cout << MAGENTA << std::endl;
	system("leaks -q form");
	std::cout << RESET << std::endl;
}