/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:42:02 by wxuerui           #+#    #+#             */
/*   Updated: 2023/05/29 15:27:36 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap default constructor called." << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	return;
}

FragTrap::FragTrap(const std::string& name) {
	std::cout << "FragTrap name constructor called." << std::endl;
	this->_name = name;
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	return;
}

FragTrap::FragTrap(const FragTrap& copy) {
	std::cout << "FragTrap copy constructor called." << std::endl;
	this->_name = copy._name;
	this->_hp = copy._hp;
	this->_ep = copy._ep;
	this->_ad = copy._ad;
	return;
}

FragTrap&	FragTrap::operator=(const FragTrap& copy) {
	std::cout << "FragTrap copy assignment operator called." << std::endl;
	this->_name = copy._name;
	this->_hp = copy._hp;
	this->_ep = copy._ep;
	this->_ad = copy._ad;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called." << std::endl;
	return;
}

// void	FragTrap::attack(const std::string& target) {
// 	if (this->_hp == 0) {
// 		std::cout << RED << "FragTrap " << this->_name << " died. Stop acting." << RESET << std::endl;
// 		return;
// 	} else if (this->_ep == 0) {
// 		std::cout << CYAN << "FragTrap " << this->_name << " is out of energy points." << RESET << std::endl;
// 		return;
// 	}

// 	std::cout << BLUE << "FragTrap " << this->_name << " attacks " << target
// 		<< ", causing " << this->_ad << " points of damage!"
// 		<< RESET << std::endl;

// 	this->_ep--;
// }

void	FragTrap::highFivesGuys(void) {
	std::cout << GREEN << this->_name << " said: \"Let's high five guys!\"" << RESET << std::endl;
}
