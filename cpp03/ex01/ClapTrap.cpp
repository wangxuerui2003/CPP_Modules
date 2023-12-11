/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:18:51 by wxuerui           #+#    #+#             */
/*   Updated: 2023/05/31 11:42:08 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "colors.h"

ClapTrap::ClapTrap() : _name("default claptrap"), _hp(10), _ep(10), _ad(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hp(10), _ep(10), _ad(0) {
	std::cout << "ClapTrap name constructor for " << name << " called" << RESET << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	std::cout << "ClapTrap copy constructor called" << RESET << std::endl;
	this->_name = copy._name;
	this->_hp = copy._hp;
	this->_ep = copy._ep;
	this->_ad = copy._ad;
	return;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& copy) {
	std::cout << "ClapTrap copy assignment operator called" << RESET << std::endl;
	this->_name = copy._name;
	this->_hp = copy._hp;
	this->_ep = copy._ep;
	this->_ad = copy._ad;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << RESET << std::endl;
	return;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_hp == 0) {
		std::cout << RED << "ClapTrap " << this->_name << " died. Stop acting." << RESET << std::endl;
		return;
	} else if (this->_ep == 0) {
		std::cout << CYAN << "ClapTrap " << this->_name << " is out of energy points." << RESET << std::endl;
		return;
	}

	std::cout << BLUE << "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_ad << " points of damage!"
		<< RESET << std::endl;

	this->_ep--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hp == 0) {
		std::cout << RED << "ClapTrap " << this->_name << " died. Stop acting." << RESET << std::endl;
		return;
	}

	if (amount >= this->_hp) {
		this->_hp = 0;
		std::cout << RED << "ClapTrap " << this->_name << " died." << RESET << std::endl;
	} else {
		this->_hp -= amount;
	}
	
	std::cout << MAGENTA << "ClapTrap " << this->_name << " took " << amount << " points of damage! "
		<< this->_hp << " hp points left for " << this->_name << "!"
		<< RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hp == 0) {
		std::cout << RED << "ClapTrap " << this->_name << " died. Stop acting." << RESET << std::endl;
		return;
	} else if (this->_ep == 0) {
		std::cout << CYAN << "ClapTrap " << this->_name << " is out of energy points." << RESET << std::endl;
		return;
	}
	
	this->_hp += amount;
	this->_ep--;
	
	std::cout << YELLOW << "ClapTrap " << this->_name << " repaired " << amount << " points of hp!" << RESET << std::endl;
}
