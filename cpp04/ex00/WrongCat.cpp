/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:34:26 by wxuerui           #+#    #+#             */
/*   Updated: 2023/06/07 21:29:36 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat constructor called." << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) {
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	this->_type = copy._type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called." << std::endl;
}

void	WrongCat::makeSound(void) const {
	std::cout << "Meow Meow Meow..." << std::endl;
}