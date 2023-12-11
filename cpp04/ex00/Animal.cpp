/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:47:39 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 14:10:55 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal& copy) {
	std::cout << "Animal copy constructor called." << std::endl;
	*this = copy;
}

Animal&	Animal::operator=(const Animal& copy) {
	std::cout << "Animal copy assignment operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called." << std::endl;
}

void Animal::makeSound(void) const {
	std::cout << "Some random sound..." << std::endl;
}

const std::string&	Animal::getType(void) const {
	return this->_type;
}