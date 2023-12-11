/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:32:17 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/19 15:50:40 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	
	Zombie	*heapZombie = newZombie("heapZombie");
	randomChump("stackZombie");
	heapZombie->annouce();
	delete heapZombie;
	// system("leaks -q zombie");
}