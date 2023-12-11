/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:36:52 by wxuerui           #+#    #+#             */
/*   Updated: 2023/05/31 11:46:26 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "Diamond default constructor called." << std::endl;
	return;
}

DiamondTrap::DiamondTrap(const std::string& name) {
	this->_name = name;
	ClapTrap::_name = this->_name + "_clap_name";
	ScavTrap::_name = this->_name;
	FragTrap::_name = this->_name;
	std::cout << "Diamond name constructor called." << std::endl;
	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) {
	this->_name = copy._name;
	this->_hp = copy._hp;
	this->_ep = copy._ep;
	this->_ad = copy._ad;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& copy) {
	this->_name = copy._name;
	this->_hp = copy._hp;
	this->_ep = copy._ep;
	this->_ad = copy._ad;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Diamond destructor called." << std::endl;
	return;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << GREEN << "My name is " << this->_name
			<< " and my ClapTrap name is " << ClapTrap::_name
			<< RESET << std::endl;
}

unsigned int	DiamondTrap::getAd(void) {
	return this->_ad;
}

unsigned int	DiamondTrap::getEp(void) {
	return this->_ep;
}
