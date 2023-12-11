/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:50:04 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/19 17:29:47 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "colors.h"
#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanA {
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void	attack(void);

	private:
		Weapon&		_weapon;
		std::string	_name;
	
};

#endif
