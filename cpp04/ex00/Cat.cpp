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
}

Cat::Cat(const Cat& copy) {
	std::cout << "Cat copy constructor called." << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy) {
	std::cout << "Cat copy assignment operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << "Meow Meow Meow..." << std::endl;
}