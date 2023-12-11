/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:47:00 by wxuerui           #+#    #+#             */
/*   Updated: 2023/05/29 10:58:21 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define ATTACK_DAMAGE 30

int	main(void) {
	FragTrap	ft1("ft1"), ft2("ft2");

	ft1.attack("ft2");
	ft2.takeDamage(ATTACK_DAMAGE);
	ft2.beRepaired(2);
	ft2.attack("ft1");
	ft1.takeDamage(ATTACK_DAMAGE);
	ft1.beRepaired(2);

	ft1.attack("ft2");
	ft2.takeDamage(ATTACK_DAMAGE);
	ft2.beRepaired(2);
	ft2.attack("ft1");
	ft1.takeDamage(ATTACK_DAMAGE);
	ft1.beRepaired(2);

	ft1.highFivesGuys();
	ft2.highFivesGuys();
	

	// Tests for killing a Fragtrap

	ft1.attack("ft2");
	ft2.takeDamage(ATTACK_DAMAGE);
	ft2.beRepaired(2);
	ft2.attack("ft1");
	ft1.takeDamage(ATTACK_DAMAGE);
	ft1.beRepaired(2);

	// ft1.attack("ft2");
	// ft2.takeDamage(ATTACK_DAMAGE);
	// ft2.beRepaired(2);
	// ft2.attack("ft1");
	// ft1.takeDamage(ATTACK_DAMAGE);
	// ft1.beRepaired(2);

}