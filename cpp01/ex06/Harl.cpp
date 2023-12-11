/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:46:34 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/20 13:53:44 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	return;
}

Harl::~Harl() {
	return;
}

void	Harl::complain(std::string level) {

	int	index = -1;
	
	std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			index = i;
			break;
		}
	}

	switch (index) {
		case 0:
			this->_debug();
		case 1:
			this->_info();
		case 2:
			this->_warning();
		case 3:
			this->_error();
			break;
		default:
			std::cout << "Unknown level: " << level << std::endl;
	}
}

void	Harl::_debug(void) {
	std::cout << MAGENTA << "Debug Level" << RESET << std::endl;
}

void	Harl::_info(void) {
	std::cout << CYAN << "Info Level" << RESET << std::endl;
}

void	Harl::_warning(void) {
	std::cout << YELLOW << "Warning Level" << RESET << std::endl;
}

void	Harl::_error(void) {
	std::cout << RED << "Error Level" << RESET << std::endl;
}