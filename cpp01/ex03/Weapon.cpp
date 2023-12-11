/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:50:20 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/19 17:29:58 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {

	return;
}

Weapon::~Weapon() {

	return;
}

const std::string&	Weapon::getType(void) const {

	return this->_type;
}

void	Weapon::setType(std::string type) {

	this->_type = type;
}
