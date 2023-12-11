/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 22:24:27 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/26 22:25:56 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "colors.h"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << BLUE << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}