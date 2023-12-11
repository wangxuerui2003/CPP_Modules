/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:46:49 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/27 13:11:11 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>

void test0(void) {
	std::cout << GREEN << "TEST 0: basic test" << RESET << std::endl;

	Bureaucrat b("john", 100);
	std::cout << b;
}

void test1(void) {
	std::cout << GREEN << "\nTEST 1: grade too high and too low while constructing" << RESET << std::endl;

	try {
		Bureaucrat b1("john", 0); // grade too high
	} catch (std::exception& e) {
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	try {
		Bureaucrat b2("doe", 151); // grade too low
	} catch (std::exception& e) {
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}

void test2(void) {
	std::cout << GREEN << "\nTEST 2: grade too high and too low after increment or decrement" << RESET << std::endl;

	try {
		Bureaucrat b1("john", 1);
		std::cout << b1;
		b1.incGrade();
	} catch (std::exception& e) {
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	try {
		Bureaucrat b2("doe", 150);
		std::cout << b2;
		b2.decGrade();
	} catch (std::exception& e) {
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}

int main(void) {
	test0();
	test1();
	test2();
	
	std::cout << MAGENTA << std::endl;
	system("leaks -q bureaucrat");
	std::cout << RESET << std::endl;
}