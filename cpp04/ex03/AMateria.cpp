/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:31:29 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 14:00:33 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "colors.h"

AMateria::AMateria(std::string const& type) : m_type(type), m_equiped(false) {
	std::cout << YELLOW << "AMateria type constructor called." << RESET << std::endl;
}

AMateria::AMateria(const AMateria& copy) : m_equiped(false) {
	std::cout << YELLOW << "AMateria copy constructor called." << RESET << std::endl;
	*this = copy;
}

AMateria& AMateria::operator=(const AMateria& copy) {
	std::cout << YELLOW << "AMateria copy assignment operator called." << RESET << std::endl;
	m_equiped = copy.isEquiped();
	return *this;
}

AMateria::~AMateria() {
	std::cout << RED << "AMateria destructor called." << RESET << std::endl;
}

bool AMateria::isEquiped(void) const {
	return m_equiped;
}

void AMateria::setEquiped(bool equiped) {
	m_equiped = equiped;
}

std::string const &AMateria::getType(void) const {
	return m_type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* Applied an Materia at " << target.getName() << " *" << std::endl;
}