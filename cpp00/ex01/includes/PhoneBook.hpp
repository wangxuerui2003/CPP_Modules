/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:05:25 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/13 15:29:37 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"
# include "colors.h"

# define N_CONTACTS 8

class PhoneBook {
	public:
		PhoneBook(); // Constructor
		PhoneBook(const PhoneBook& copy); // Copy constructor
		~PhoneBook(); // Destructor
		PhoneBook&	operator=(const PhoneBook&); // Assignment operator

		void  addContact();
		void  searchContact();

	private:
		Contact	_contacts[N_CONTACTS];
		int		_numContacts;
		int		_currentContactNo;
};

#endif
