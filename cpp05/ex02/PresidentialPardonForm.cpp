/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:16:56 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/26 13:12:42 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5) {
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy.getName(), 25, 5) {
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	(void)copy;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	
}

void PresidentialPardonForm::formAction(void) const {
	std::cout << GREEN << getName() << " has been pardoned by Zaphod Beeblebrox!" << RESET << std::endl;

}
