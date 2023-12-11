/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:49:17 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 14:03:07 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "colors.h"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character() : m_name("a character") {
	std::cout << YELLOW << "Character default constructor called." << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		m_inventory[i] = NULL;
	}
}

Character::Character(const char *name) : m_name(name) {
	std::cout << YELLOW << "Character name constructor overload called." << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		m_inventory[i] = NULL;
	}
}

Character::Character(const Character& copy) {
	std::cout << YELLOW << "Character copy constructor called." << RESET << std::endl;
	*this = copy;
}

Character& Character::operator=(const Character& copy) {
	std::cout << YELLOW << "Character copy constructor called." << RESET << std::endl;
	m_name = copy.getName();
	for (int i = 0; i < 4; i++) {
		if (copy.m_inventory[i] != NULL) {
			m_inventory[i] = copy.m_inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character() {
	std::cout << RED << "Character destructor called." << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		if (m_inventory[i] != NULL && m_inventory[i]->isEquiped()) {
			delete m_inventory[i];
		}
	}
}

std::string const & Character::getName() const {
	return m_name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (m_inventory[i] == NULL) {
			m->setEquiped(true);
			m_inventory[i] = m;
			std::cout << BLUE << m_name << " has equiped a materia " << m->getType() << RESET << std::endl;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || m_inventory[idx] == NULL) {
		return;
	}
	m_inventory[idx]->setEquiped(false);
	m_inventory[idx] = NULL;
	std::cout << BLUE << m_name << " has unequiped the materia at index " << idx << RESET << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || m_inventory[idx] == NULL) {
		return;
	}
	m_inventory[idx]->use(target);
}