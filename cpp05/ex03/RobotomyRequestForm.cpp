/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:16:56 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/26 13:12:42 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy.getName(), 72, 45) {
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	(void)copy;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	
}

void	RobotomyRequestForm::formAction(void) const {
	std::cout << "Noise....." << std::endl;
	if (rand() % 2 == 1) {
		std::cout << BLUE << getName() << " has been robotomized successfully" << RESET << std::endl;
	} else {
		std::cout << MAGENTA << getName() << " fail to be robotomized." << RESET << std::endl;
	}
}
