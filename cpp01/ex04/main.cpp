/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:35:58 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/19 19:15:08 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.h"

int	main(int ac, char **av) {

	if (ac != 4) {
		std::cerr << CYAN << "Usage: ./winnder_sed <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	if (sed(av[1], av[2], av[3]) == false) {
		return 1;
	}

	return 0;
}