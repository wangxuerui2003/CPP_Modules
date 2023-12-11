/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:40:07 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/27 15:23:13 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "utils.h"
#include "colors.h"

Base	*generate(void) {
	int type = rand() % 3;
	if (type == 0) {
		std::cout << "Generated a A type ptr" << std::endl;
		return new A;
	} else if (type == 1) {
		std::cout << "Generated a B type ptr" << std::endl;
		return new B;
	} else {
		std::cout << "Generated a C type ptr" << std::endl;
		return new C;
	}
}

void	identify(Base *p) {
	if (dynamic_cast<A *>(p) != NULL) {
		std::cout << YELLOW << "Pointer Type A*" << RESET << std::endl;
	} else if (dynamic_cast<B *>(p) != NULL) {
		std::cout << YELLOW << "Pointer Type B*" << RESET << std::endl;
	} else if (dynamic_cast<C *>(p) != NULL) {
		std::cout << YELLOW << "Pointer Type C*" << RESET << std::endl;
	} else {
		std::cout << RED << "Unknown pointer type!" << RESET << std::endl;
	}
}

void	identify(Base& ref) {
	try {
		(void)dynamic_cast<A&>(ref);
		std::cout << YELLOW << "Ref typr A&" << RESET << std::endl;
		return;
	} catch (...) {} // Exception type is std::bad_cast

	try {
		(void)dynamic_cast<B&>(ref);
		std::cout << YELLOW << "Ref typr B&" << RESET << std::endl;
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(ref);
		std::cout << YELLOW << "Ref typr C&" << RESET << std::endl;
		return;
	} catch (...) {}

	std::cout << RED << "Unknown reference type!" << RESET << std::endl;
}