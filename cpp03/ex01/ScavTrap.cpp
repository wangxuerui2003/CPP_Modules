/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:11:37 by wxuerui           #+#    #+#             */
/*   Updated: 2023/05/29 10:49:33 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called." << std::endl;
	return;
}

ScavTrap::ScavTrap(const std::string& name) {
	std::cout << "ScavTrap name constructor called." << std::endl;
	this->_name = name;
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	this->_isGatekeeperMode = 0;
	return;
}

ScavTrap::ScavTrap(const ScavTrap& copy) {
	std::cout << "ScavTrap copy constructor called." << std::endl;
	this->_name = copy._name;
	this->_hp = copy._hp;
	this->_ep = copy._ep;
	this->_ad = copy._ad;
	this->_isGatekeeperMode = 0;
	return;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& copy) {
	std::cout << "ScavTrap copy assignment operator called." << std::endl;
	this->_name = copy._name;
	this->_hp = copy._hp;
	this->_ep = copy._ep;
	this->_ad = copy._ad;
	this->_isGatekeeperMode = 0;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called." << std::endl;
	return;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->_hp == 0) {
		std::cout << RED << "ScavTrap " << this->_name << " died. Stop acting." << RESET << std::endl;
		return;
	} else if (this->_ep == 0) {
		std::cout << CYAN << "ScavTrap " << this->_name << " is out of energy points." << RESET << std::endl;
		return;
	}

	std::cout << BLUE << "ScavTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_ad << " points of damage!"
		<< RESET << std::endl;

	this->_ep--;
}

void	ScavTrap::guardGate(void) {
	if (this->_isGatekeeperMode != 0) {
		std::cout << this->_name << " is already in gate keeper mode." << std::endl;
		return;
	}
	this->_isGatekeeperMode = 1;
	std::cout << YELLOW << this->_name << " is now in gate keeper mode." << RESET << std::endl;
}