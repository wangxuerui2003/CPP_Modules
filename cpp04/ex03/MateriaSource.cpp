/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:52:17 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 13:52:53 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "colors.h"

MateriaSource::MateriaSource() {
	std::cout << YELLOW << "MateriaSource default constructor called." << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		m_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	std::cout << YELLOW << "MateriaSource copy constructor called." << RESET << std::endl;
	*this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy) {
	std::cout << YELLOW << "MateriaSource copy assignment operator called." << RESET << std::endl;
	// Deep copy
	for (int i = 0; i < 4; i++) {
		m_materias[i] = copy.m_materias[i];
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << RED << "MateriaSouce destructor called." << RESET << std::endl;
	for (int i = 0; i < 4; i++) {
		if (m_materias[i] != NULL) {
			delete m_materias[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (m_materias[i] == NULL) {
			m_materias[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 3; i >= 0; i--) {
		if (m_materias[i] != NULL && m_materias[i]->getType() == type) {
			return m_materias[i]->clone();
		}
	}
	return NULL;
}