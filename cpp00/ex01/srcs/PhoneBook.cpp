/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:32:55 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/18 12:14:08 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	_currentContactNo = 0;
	_numContacts = 0;
	return;
}

PhoneBook::PhoneBook(const PhoneBook& copy) {
	*this = copy;
}

PhoneBook::~PhoneBook() {
	return;
}

PhoneBook&	PhoneBook::operator=(const PhoneBook& copy) {
	for (int i = 0; i < N_CONTACTS; i++) {
		_contacts[i] = copy._contacts[i];
	}
	_currentContactNo = copy._currentContactNo;
	_numContacts = copy._currentContactNo;
  	return *this;
}

static int	isNumber(std::string num) {
	if (num.length() == 0) {
		return 0;
	}
	for (unsigned int i = 0; i < num.length(); i++) {
		if (std::isdigit(num[i]) == 0) {
			return 0;
		}
	}
	return 1;
}

void	PhoneBook::addContact() {

	std::string	contactInfo[5];

	_currentContactNo++;
	if (_numContacts < N_CONTACTS) {
		_numContacts++;
	}

	while (contactInfo[FN].length() == 0) {
	  	std::cout << "First Name: ";
    	std::getline(std::cin, contactInfo[FN], '\n');
	}
	while (contactInfo[LN].length() == 0) {
	  	std::cout << "Last Name: ";
    	std::getline(std::cin, contactInfo[LN], '\n');
	}
	while (contactInfo[NN].length() == 0) {
	  	std::cout << "Nickname: ";
		std::getline(std::cin, contactInfo[NN], '\n');
	}
	while (contactInfo[PN].length() == 0 || !isNumber(contactInfo[PN])) {
	  std::cout << "Phone Number: ";
    	std::getline(std::cin, contactInfo[PN], '\n');
	}
	while (contactInfo[DS].length() == 0) {
	  std::cout << "Darkest Secret: ";
    	std::getline(std::cin, contactInfo[DS], '\n');
	}
  	std::cout << std::endl;

	_contacts[(_currentContactNo - 1) % N_CONTACTS].setContactInfo(contactInfo);
}

static void	printColumn(std::string str) {

	std::cout << "|";
  	if (str.length() < 10) {
    	std::cout << std::setw(10) << std::right << str;
  	} else {
    	str.resize(9);
    	std::cout << str << '.';
  	}
}

static void	printRow(std::string contactInfo[5], int index) {
	printColumn(std::to_string(index));
	printColumn(contactInfo[FN]);
	printColumn(contactInfo[LN]);
	printColumn(contactInfo[NN]);
	std::cout << "|" << std::endl;
}

/**
 * 4 columns, index, fn, ln and nn. Each column is 10 characters wide and info are right aligned.
 * 
*/
void	PhoneBook::searchContact() {
	
  	std::string index_buffer;

	if (this->_numContacts == 0) {
		std::cout << "No contacts to search!" << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------" << std::endl;
	printColumn("index");
	printColumn("firstname");
	printColumn("lastname");
	printColumn("nickname");
	std::cout << "|" << std::endl;
	
	for (int i = 0; i < _numContacts; i++) {
		std::cout << "---------------------------------------------" << std::endl;
		printRow(_contacts[i].getContactInfo(), i + 1);
	}
	std::cout << "---------------------------------------------" << std::endl;
  	while (!isNumber(index_buffer) || (std::stoi(index_buffer) > _numContacts || std::stoi(index_buffer) == 0)) {
    	std::cout << GREEN << "Search by index: " << RESET;
    	std::getline(std::cin, index_buffer, '\n');
 	}
  
	_contacts[std::stoi(index_buffer) - 1].printContact();
}
