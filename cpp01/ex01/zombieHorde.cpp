/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:53:42 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/19 16:23:56 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	
	Zombie	*zombies = new Zombie[N];
	for (int i = 0; i < N; i++) {
		std::cout << BLUE << i << ": ";
		zombies[i].setName(name);
	}
	return zombies;
}