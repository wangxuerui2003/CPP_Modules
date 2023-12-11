/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:49:56 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/19 17:30:00 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon), _name(name) {
	
	return;
}

HumanA::~HumanA() {

	return;
}

void	HumanA::attack() {
	
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
