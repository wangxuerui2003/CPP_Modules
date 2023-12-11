/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:26:47 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 14:00:41 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "colors.h"

Cure::Cure() : AMateria("cure") {
	std::cout << YELLOW << "Cure default constructor called." << RESET << std::endl;
}

Cure::Cure(const Cure& copy) : AMateria("cure") {
	std::cout << YELLOW << "Cure copy constructor called." << RESET << std::endl;
	*this = copy;
}

Cure& Cure::operator=(const Cure& copy) {
	std::cout << YELLOW << "Cure copy assignment operator called." << RESET << std::endl;
	m_equiped = copy.isEquiped();
	return *this;
}

Cure::~Cure() {
	std::cout << RED << "Cure destructor called." << RESET << std::endl;
}

AMateria *Cure::clone() const {
	AMateria	*copy = new Cure;

	return copy;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
