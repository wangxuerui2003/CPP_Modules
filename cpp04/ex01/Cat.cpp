/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:56:53 by wxuerui           #+#    #+#             */
/*   Updated: 2023/06/07 21:29:36 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called." << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& copy) {
	std::cout << "Cat copy constructor called." << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy) {
	std::cout << "Cat copy assignment operator called." << std::endl;
	this->_type = copy._type;
	*(this->_brain) = *(copy._brain);
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
	delete this->_brain;
}

void	Cat::makeSound(void) const {
	std::cout << "Meow Meow Meow..." << std::endl;
}

void	Cat::setIdea(std::string idea) {
	_brain->setIdea(idea);
}

const std::string&	Cat::getIdea(int index) const {
	return _brain->getIdea(index);
}