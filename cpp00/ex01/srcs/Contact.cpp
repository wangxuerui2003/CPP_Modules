/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:09:50 by wxuerui           #+#    #+#             */
/*   Updated: 2022/09/15 09:19:19 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include <string>

// Default Constructor of the Contact class
Contact::Contact(void)
{

}

// Copy Constructor of the Contact class
Contact::Contact(const Contact &copy)
{
	(void)copy;
}

// Destructor of the Contact class
Contact::~Contact(void)
{

}

void	Contact::setContact(std::string firstname,
							std::string lastname, std::string nickname,
							std::string phonenumber, std::string darkest_secret)
{
	this->_firstname = firstname;
	this->_lastname = lastname;
	this->_nickname = nickname;
	this->_phonenumber = phonenumber;
	this->_darkest_secret = darkest_secret;
}

std::string	Contact::getFirstname(void)
{
	return (_firstname);
}

std::string	Contact::getLastname(void)
{
	return (_lastname);
}

std::string	Contact::getNickname(void)
{
	return (_nickname);
}

void	Contact::printContact(void)
{
	std::cout << "Firstname: " << this->_firstname << std::endl;
	std::cout << "Lastname: " << this->_lastname << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "PhoneNumber: " << this->_phonenumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkest_secret << std::endl;
}

