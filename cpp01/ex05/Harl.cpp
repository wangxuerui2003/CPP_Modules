/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:24:54 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/20 12:51:25 by wxuerui          ###   ########.fr       */
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

	std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	void (Harl::*mfs[4])(void) = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*mfs[i])();
			return;
		}
	}

	std::cout << "Unknown level: " << level << std::endl;
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