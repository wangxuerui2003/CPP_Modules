/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:52:43 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/19 16:19:37 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {

	std::cout << GREEN << "A new zombie has spawned." << RESET << std::endl;
	return;
}

Zombie::Zombie(std::string name) {

	this->_name = name;
	std::cout << GREEN << "A new zombie \"" << this->_name << "\" has spawned." << RESET << std::endl;
	return;
}

Zombie::~Zombie() {
	
	std::cout << RED << this->_name << " has been destroyed." << RESET << std::endl;
	return;
}

void	Zombie::annouce(void) {
	
	std::cout << YELLOW << this->_name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
	std::cout << BLUE << "A zombie's name has been setted to " << this->_name << RESET << std::endl;
}
