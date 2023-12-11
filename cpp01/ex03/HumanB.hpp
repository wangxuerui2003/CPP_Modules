/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:49:38 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/19 17:29:49 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "colors.h"
#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanB {
	public:
		HumanB(std::string name);
		~HumanB();
		
		void	attack(void);
		void	setWeapon(Weapon& weapn);

	private:
		Weapon		*_weapon;
		std::string	_name;
	
};

#endif
