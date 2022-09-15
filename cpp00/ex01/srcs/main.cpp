/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:49:29 by wxuerui           #+#    #+#             */
/*   Updated: 2022/09/15 09:11:06 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

static void	printHint(void)
{
	std::cout << "\"ADD\"   : Add a new contact" << std::endl;
	std::cout << "\"SEARCH\": Search for a contact" << std::endl;
	std::cout << "\"EXIT\"  : Exits the phonebook program" << std::endl;
}

int	main(void)
{
	std::string	option;
	PhoneBook	phonebook;

	while (true)
	{
		printHint();
		std::cout << "option: ";
		getInput(&option);
		if (option == "ADD")
			phonebook.addContact();
		if (option == "SEARCH")
			phonebook.searchContact();
		if (option == "EXIT")
			exit(0);
	}
	return (0);
}
