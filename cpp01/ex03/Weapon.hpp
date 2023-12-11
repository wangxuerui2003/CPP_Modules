/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:50:28 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/19 17:29:45 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include "colors.h"
#include <iostream>
#include <string>

class	Weapon {
	public:
		Weapon(std::string type);
		~Weapon();

		const std::string&	getType(void) const;
		void	setType(std::string type);

	private:
		std::string	_type;
	
};


#endif
