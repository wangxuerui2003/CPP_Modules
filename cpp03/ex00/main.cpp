/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:47:00 by wxuerui           #+#    #+#             */
/*   Updated: 2023/05/29 09:57:24 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define ATTACK_DAMAGE 0

int	main(void) {
	ClapTrap	ct1("ct1"), ct2("ct2");

	ct1.attack("ct2");
	ct2.takeDamage(ATTACK_DAMAGE);
	ct2.beRepaired(2);
	ct2.attack("ct1");
	ct1.takeDamage(ATTACK_DAMAGE);
	ct1.beRepaired(2);

	ct1.attack("ct2");
	ct2.takeDamage(ATTACK_DAMAGE);
	ct2.beRepaired(2);
	ct2.attack("ct1");
	ct1.takeDamage(ATTACK_DAMAGE);
	ct1.beRepaired(2);
	

	// Tests for using up energy points

	// ct1.attack("ct2");
	// ct2.takeDamage(ATTACK_DAMAGE);
	// ct2.beRepaired(2);
	// ct2.attack("ct1");
	// ct1.takeDamage(ATTACK_DAMAGE);
	// ct1.beRepaired(2);

	// ct1.attack("ct2");
	// ct2.takeDamage(ATTACK_DAMAGE);
	// ct2.beRepaired(2);
	// ct2.attack("ct1");
	// ct1.takeDamage(ATTACK_DAMAGE);
	// ct1.beRepaired(2);

	// ct1.attack("ct2");
	// ct2.takeDamage(ATTACK_DAMAGE);
	// ct2.beRepaired(2);
	// ct2.attack("ct1");
	// ct1.takeDamage(ATTACK_DAMAGE);
	// ct1.beRepaired(2);

	// ct1.attack("ct2");
	// ct2.takeDamage(ATTACK_DAMAGE);
	// ct2.beRepaired(2);
	// ct2.attack("ct1");
	// ct1.takeDamage(ATTACK_DAMAGE);
	// ct1.beRepaired(2);
}