/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:43:23 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/20 13:54:07 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av) {

	Harl	harl;
	if (ac != 2) {
		std::cerr << YELLOW << "Usage: ./harlFilter <level>" << RESET << std::endl;
		return 1;
	}

	harl.complain(av[1]);
}