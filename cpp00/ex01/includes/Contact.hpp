/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:09:03 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/18 12:18:31 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

enum ContactInfoIndex {
	FN, // First name
	LN, // Last name
	NN, // Nickname
	PN, // Phone number
	DS // Darkest secret
};

class Contact {
	public:
		Contact(); // Constructor
		Contact(const Contact& copy); // Copy constructor
		~Contact(); // Destructor
		Contact& operator=(const Contact&); // Assignment operator

		void  setContactInfo(std::string contactInfo[5]);
		std::string *getContactInfo();
    	void  printContact();

	private:
		std::string	_contactInfo[5];
};

#endif
