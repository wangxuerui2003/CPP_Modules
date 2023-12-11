/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:05:12 by wxuerui           #+#    #+#             */
/*   Updated: 2023/05/31 11:33:19 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "colors.h"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& copy);
		DiamondTrap& operator=(const DiamondTrap& copy);
		~DiamondTrap();

		using ScavTrap::attack;
		void	whoAmI(void);

		unsigned int	getAd(void);
		unsigned int	getEp(void);
		// int	test(int test) { _test = test; return test; };
	
	private:
		std::string	_name;
		using FragTrap::_hp;
		using ScavTrap::_ep;
		using FragTrap::_ad;
		// int	_test;
};

#endif
