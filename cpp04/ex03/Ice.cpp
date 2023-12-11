/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:48:29 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 14:00:38 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "colors.h"

Ice::Ice() : AMateria("ice") {
	std::cout << YELLOW << "Ice default constructor called." << RESET << std::endl;
}

Ice::Ice(const Ice& copy) : AMateria("ice") {
	std::cout << YELLOW << "Ice copy constructor called." << RESET << std::endl;
	*this = copy;
}

Ice& Ice::operator=(const Ice& copy) {
	std::cout << YELLOW << "Ice copy assignment operator called." << RESET << std::endl;
	m_equiped = copy.isEquiped();
	return *this;
}

Ice::~Ice() {
	std::cout << RED << "Ice destructor called." << RESET << std::endl;
}

AMateria *Ice::clone() const {
	AMateria	*copy = new Ice;

	return copy;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
