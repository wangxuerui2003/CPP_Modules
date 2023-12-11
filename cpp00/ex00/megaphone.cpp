/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:10:22 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/12 15:28:29 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j] != 0; j++)
		{
			if (av[i][j] >= 97 && av[i][j] <= 122)
				std::cout << (char)std::toupper(av[i][j]);
			else
				std::cout << av[i][j];
		}
	}
	std::cout << std::endl;
}

