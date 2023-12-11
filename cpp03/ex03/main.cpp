/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:47:00 by wxuerui           #+#    #+#             */
/*   Updated: 2023/05/31 11:47:00 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define ATTACK_DAMAGE 30

int	main(void) {
	DiamondTrap	dt1("dt1"), dt2("dt2");

	dt1.attack("dt2");
	dt2.takeDamage(dt1.getAd());
	dt2.beRepaired(2);
	dt2.attack("dt1");
	dt1.takeDamage(dt2.getAd());
	dt1.beRepaired(2);

	dt1.attack("dt2");
	dt2.takeDamage(dt1.getAd());
	dt2.beRepaired(2);
	dt2.attack("dt1");
	dt1.takeDamage(dt2.getAd());
	dt1.beRepaired(2);

	dt1.whoAmI();
	dt2.whoAmI();

	// Tests for killing dt2

	// dt1.attack("dt2");
	// dt2.takeDamage(dt1.getAd());
	// dt2.beRepaired(2);
	// dt2.attack("dt1");
	// dt1.takeDamage(dt2.getAd());
	// dt1.beRepaired(2);

	// dt1.attack("dt2");
	// dt2.takeDamage(dt1.getAd());
	// dt2.beRepaired(2);
	// dt2.attack("dt1");
	// dt1.takeDamage(dt2.getAd());
	// dt1.beRepaired(2);

	std::cout << YELLOW << "dt1 ep left: " << dt1.getEp() << RESET << std::endl;
	std::cout << YELLOW << "dt2 ep left: " << dt2.getEp() << RESET << std::endl;


}
