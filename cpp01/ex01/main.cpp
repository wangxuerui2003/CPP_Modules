/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:51:38 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/19 16:23:41 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define SIZE 10

int	main(void) {

	std::cout << "Initialize" << std::endl;
	Zombie	*zombies = zombieHorde(SIZE, "Dolphin Rider");

	std::cout << "\nAnnouce" << std::endl;
	for (int i = 0; i < SIZE; i++) {
		zombies[i].annouce();
	}
	
	std::cout << "\nDelete" << std::endl;
	delete[] zombies;
	// system("leaks -q zombiehorde");
}