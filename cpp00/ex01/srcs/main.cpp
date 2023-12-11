/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:33:25 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/18 12:17:55 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "colors.h"

int	main(void) {

	PhoneBook	phoneBook;
	std::string	input;

	while (1) {
    	std::cout << YELLOW << "Enter a command (ADD, SEARCH, EXIT): " << RESET;
		std::getline(std::cin, input, '\n');
		if (input == "ADD") {
			phoneBook.addContact();
		} else if (input == "SEARCH") {
			phoneBook.searchContact();
		} else if (input == "EXIT") {
      		std::cout << CYAN << "EXIT" << RESET;
			break;
		} else {
			std::cerr << MAGENTA << input << ": " << RED << "Command Not Found!" << RESET << std::endl;
		}
	}
  	std::cout << std::endl;

	return 0;
}
