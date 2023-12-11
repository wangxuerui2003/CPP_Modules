/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:31:11 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 14:11:47 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = copy;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& copy) {
	std::cout << "WrongAnimal copy assignment operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called." << std::endl;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "Some random sound..." << std::endl;
}

const std::string&	WrongAnimal::getType(void) const {
	return this->_type;
}