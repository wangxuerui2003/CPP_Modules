/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:47:00 by wxuerui           #+#    #+#             */
/*   Updated: 2023/05/29 10:48:57 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define ATTACK_DAMAGE 20

int	main(void) {
	ScavTrap	st1("st1"), st2("st2");

	st1.attack("st2");
	st2.takeDamage(ATTACK_DAMAGE);
	st2.beRepaired(2);
	st2.attack("st1");
	st1.takeDamage(ATTACK_DAMAGE);
	st1.beRepaired(2);

	st1.attack("st2");
	st2.takeDamage(ATTACK_DAMAGE);
	st2.beRepaired(2);
	st2.attack("st1");
	st1.takeDamage(ATTACK_DAMAGE);
	st1.beRepaired(2);

	st1.guardGate();
	st1.guardGate();

	st2.guardGate();
	

	// Tests for killing a ScavTrap

	// st1.attack("st2");
	// st2.takeDamage(ATTACK_DAMAGE);
	// st2.beRepaired(2);
	// st2.attack("st1");
	// st1.takeDamage(ATTACK_DAMAGE);
	// st1.beRepaired(2);

	// st1.attack("st2");
	// st2.takeDamage(ATTACK_DAMAGE);
	// st2.beRepaired(2);
	// st2.attack("st1");
	// st1.takeDamage(ATTACK_DAMAGE);
	// st1.beRepaired(2);

	// st1.attack("st2");
	// st2.takeDamage(ATTACK_DAMAGE);
	// st2.beRepaired(2);
	// st2.attack("st1");
	// st1.takeDamage(ATTACK_DAMAGE);
	// st1.beRepaired(2);

	// st1.attack("st2");
	// st2.takeDamage(ATTACK_DAMAGE);
	// st2.beRepaired(2);
	// st2.attack("st1");
	// st1.takeDamage(ATTACK_DAMAGE);
	// st1.beRepaired(2);
}