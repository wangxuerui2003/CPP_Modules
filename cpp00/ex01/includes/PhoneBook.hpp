/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:43:21 by wxuerui           #+#    #+#             */
/*   Updated: 2022/09/14 21:15:19 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

# define MAX_CONTACTS 8
# define MAX_WIDTH 10

class	PhoneBook
{
	public:
		PhoneBook();
		PhoneBook(const PhoneBook &copy);
		virtual	~PhoneBook();
		void	addContact();
		void	searchContact();
		void	printContacts(Contact contacts[MAX_CONTACTS]);
	private:
		Contact	_contacts[MAX_CONTACTS];
		int		_index;
		int		_size;
};

void	getInput(std::string *buffer);

#endif	// PhoneBook.hpp
