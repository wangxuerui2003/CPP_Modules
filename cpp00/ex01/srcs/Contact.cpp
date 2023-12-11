/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:33:12 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/18 12:18:17 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	return;
}

Contact::Contact(const Contact& copy) {
	*this = copy;
}

Contact::~Contact() {
	return;
}

Contact&	Contact::operator=(const Contact& copy) {
	_contactInfo[FN] = copy._contactInfo[FN];
	_contactInfo[LN] = copy._contactInfo[LN];
	_contactInfo[NN] = copy._contactInfo[NN];
	_contactInfo[PN] = copy._contactInfo[PN];
	_contactInfo[DS] = copy._contactInfo[DS];	

	return *this;
}

void	Contact::setContactInfo(std::string contactInfo[5]) {
	_contactInfo[FN] = contactInfo[FN];
	_contactInfo[LN] = contactInfo[LN];
	_contactInfo[NN] = contactInfo[NN];
	_contactInfo[PN] = contactInfo[PN];
	_contactInfo[DS] = contactInfo[DS];
}

std::string	*Contact::getContactInfo() {
	return this->_contactInfo;
}

void  Contact::printContact() {
  	std::cout << "\n----------------------------------" << std::endl;
  	std::cout << "First Name: " << _contactInfo[FN] << std::endl;
  	std::cout << "Last Name: " << _contactInfo[LN] << std::endl;
  	std::cout << "Nickname: " << _contactInfo[NN] << std::endl;
  	std::cout << "Phone Number: " << _contactInfo[PN] << std::endl;
  	std::cout << "Darkest Secret: " << _contactInfo[DS] << std::endl;
  	std::cout << "----------------------------------\n" << std::endl;
}
