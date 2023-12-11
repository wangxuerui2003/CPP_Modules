/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:47:39 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 14:12:28 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "Animal constructor called." << std::endl;
	this->_brain = new Brain();
}

AAnimal::AAnimal(const AAnimal& copy) {
	std::cout << "AAnimal copy constructor called." << std::endl;
	*this = copy;
}

AAnimal&	AAnimal::operator=(const AAnimal& copy) {
	std::cout << "AAnimal copy assignment operator called." << std::endl;
	this->_type = copy._type;
	*(this->_brain) = *(copy._brain);
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called." << std::endl;
	delete this->_brain;
}

const std::string&	AAnimal::getType(void) const {
	return this->_type;
}

void	AAnimal::setIdea(std::string idea) {
	_brain->setIdea(idea);
}

const std::string&	AAnimal::getIdea(int index) const {
	return _brain->getIdea(index);
}