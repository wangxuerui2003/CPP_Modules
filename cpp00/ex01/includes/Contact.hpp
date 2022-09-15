/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:26:27 by wxuerui           #+#    #+#             */
/*   Updated: 2022/09/14 21:11:34 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>
# include <string>

class	Contact
{
	public:
		Contact();
		Contact(const Contact &copy);
		virtual	~Contact();
		void	setContact(std::string firstname, std::string lastname,
							std::string nickname, std::string phonenumber,
							std::string darkest_secret);
		std::string	getFirstname();
		std::string	getLastname();
		std::string	getNickname();
		void		printContact();
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phonenumber;
		std::string	_darkest_secret;
};

#endif	// Contact.hpp
