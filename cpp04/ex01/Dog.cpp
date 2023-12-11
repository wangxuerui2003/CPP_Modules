/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:56:53 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 20:53:13 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called." << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& copy) {
	std::cout << "Dog copy constructor called." << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	this->_type = copy._type;
	*(this->_brain) = *(copy._brain);
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
	delete this->_brain;
}

void	Dog::makeSound(void) const {
	std::cout << "Woof Woof Woof!" << std::endl;
}

void	Dog::setIdea(std::string idea) {
	_brain->setIdea(idea);
}

const std::string&	Dog::getIdea(int index) const {
	return _brain->getIdea(index);
}