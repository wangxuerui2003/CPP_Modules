/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:30:40 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/19 16:44:55 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include <iostream>
#include <string>

int	main(void) {
	
	std::string		string = "HI THIS IS BRAIN";
	std::string		*stringPTR = &string;
	std::string&	stringREF = string;
	
	/*
		References are alias to an existing object or function.
		Once a reference is initialized to refer to an object,
		it can be used to access and modify the object in the same way as the original object itself.
	*/

	std::cout << "Memory address of the str: " << &string << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
	// In my opinion it should be "the memory address of stringREF"
	
	std::cout << std::endl;

	std::cout << "Value of str: " << string << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
	// In my opinion it should be "the value of stringREF"
}