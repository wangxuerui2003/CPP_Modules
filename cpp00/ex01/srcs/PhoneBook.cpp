/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:28:17 by wxuerui           #+#    #+#             */
/*   Updated: 2022/09/15 09:10:54 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <string>

// Default Constructor of the PhoneBook class
PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	this->_size = 0;
}

// Copy Constructor of the PhoneBook class
PhoneBook::PhoneBook(const PhoneBook &copy)
{
	(void)copy;
}

// Destructor of the PhoneBook class
PhoneBook::~PhoneBook(void)
{

}

// Get input from std::cin and exit if error happens
void	getInput(std::string *buffer)
{
	if (std::getline(std::cin, *buffer).eof() == true)
	{
		std::cout << std::endl;
		std::exit(1);
	}
}

// Add contact to the phonebook
void	PhoneBook::addContact(void)
{
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darkest_secret;

	std::cout << "Firstname: ";
	getInput(&firstname);
	std::cout << "Lastname: ";
	getInput(&lastname);
	std::cout << "Nickname: ";
	getInput(&nickname);
	std::cout << "PhoneNumber: ";
	getInput(&phonenumber);
	std::cout << "Darkest secret: ";
	getInput(&darkest_secret);
	if (firstname == "" || lastname == "" || nickname == "" ||
			phonenumber == "" || darkest_secret == "")
	{
		std::cout << "Have empty field. Add contact failed" << std::endl;
		return ;
	}
	_contacts[_index].setContact(firstname, lastname, nickname,
			phonenumber, darkest_secret);
	_index = (_index + 1) % MAX_CONTACTS;
	if (_size < MAX_CONTACTS)
		_size++;
}

void	PhoneBook::printContacts(Contact contacts[MAX_CONTACTS])
{
	std::cout <<  "     Index|First name| Last name|  Nickname|" <<std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		std::cout << std::setw(MAX_WIDTH) << std::right << i << '|';
		if (contacts[i].getFirstname().length() <= MAX_WIDTH)
			std::cout << std::right << std::setw(MAX_WIDTH)
				<< contacts[i].getFirstname();
		else
			std::cout << contacts[i].getFirstname().substr(0, 9)
				<< '.';
		std::cout << '|';
		if (contacts[i].getLastname().length() <= MAX_WIDTH)
			std::cout << std::right << std::setw(MAX_WIDTH)
				<< contacts[i].getLastname();
		else
			std::cout << contacts[i].getLastname().substr(0, 9)
				<< '.';
		std::cout << '|';
		if (contacts[i].getNickname().length() <= MAX_WIDTH)
			std::cout << std::right << std::setw(MAX_WIDTH)
				<< contacts[i].getNickname();
		else
			std::cout << contacts[i].getNickname().substr(0, 9)
				<< '.';
		std::cout << '|';
		std::cout << std::endl;
	}
}

void	PhoneBook::searchContact(void)
{
	std::string	index;

	printContacts(_contacts);
	while (true)
	{
		std::cout << "Enter an index: ";
		getInput(&index);
		if ((index.length() == 1) && (index[0] >= '0')
				&& (index[0] <= '0' + MAX_CONTACTS - 1)
				&& (index[0] - '0' < this->_size))
		{
			std::cout << "--------------------" << std::endl;
			_contacts[index[0] - '0'].printContact();
			std::cout << "--------------------" << std::endl;
			return ;
		}
		std::cout << "Invalid index" << std::endl;
	}
}
