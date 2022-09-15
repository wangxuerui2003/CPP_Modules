/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:24:23 by wxuerui           #+#    #+#             */
/*   Updated: 2022/09/12 11:28:53 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j] != '\0'; j++)
			if (av[i][j] >= 'a' && av[i][j] <= 'z')
				av[i][j] -= 32;
		std::cout << av[i];
	}
	std::cout << std::endl;
	return (0);
}
