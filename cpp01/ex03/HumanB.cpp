/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:49:29 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/19 17:30:03 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon(nullptr), _name(name) {
	
	return;
}

HumanB::~HumanB() {

	return;
}

void	HumanB::attack(void) {

	if (this->_weapon == nullptr) {
		std::cout << "HumanB has no weapon yet!" << std::endl;
		return;
	}

	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {

	this->_weapon = &weapon;
	return;
}
