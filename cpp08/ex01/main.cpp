/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:26:06 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/03 13:09:00 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "colors.h"
#include <iostream>
#include <string>

void	test0() {
	std::cout << GREEN << "Test0: Base test" << RESET << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test1() {
	std::cout << GREEN << "\nTest1: Range of iterators fill up, not enough space test" << RESET << std::endl;

	Span sp(5);
	int arr[5] = {INT_MIN, 0, 1, 5, INT_MAX};
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));


	// Use the range of iterator addNumber function overload
	sp.addNumber(v.begin(), v.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try {
		sp.addNumber(123);
	} catch (std::exception& e) {
		std::cout << "Exception: " << RED << e.what() << RESET << std::endl;
	}
}

void	test2() {
	std::cout << GREEN << "\nTest2: Span too small test" << RESET << std::endl;

	{
		Span sp(5); // No number in span
		try {
			sp.shortestSpan();
		} catch (std::exception& e) {
			std::cout << "Exception: " << RED << e.what() << RESET << std::endl;
		}
	}
	{
		Span sp(5);
		sp.addNumber(10); // One number in span
		try {
			sp.longestSpan();
		} catch (std::exception& e) {
			std::cout << "Exception: " << RED << e.what() << RESET << std::endl;
		}
	}
	{
		Span sp(5);
		sp.addNumber(10);
		sp.addNumber(20); // Normal
		try {
			std::cout << sp.longestSpan() << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << "Exception: " << RED << e.what() << RESET << std::endl;
		}
	}
}

void	test3() {
	std::cout << GREEN << "\nTest3: Large data set test" << RESET << std::endl;
	
	Span sp(50000);
	for (int i = 1; i < 50001; ++i) {
		if (i == 500) {
			sp.addNumber(-100);
		} else {
			sp.addNumber(i * 2);
		}
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main(void) {
	test0();
	test1();
	test2();
	test3();
	
	return 0;
}