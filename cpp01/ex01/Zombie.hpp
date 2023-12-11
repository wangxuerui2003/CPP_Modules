/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:53:00 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/19 16:12:01 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include "colors.h"

class Zombie {
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	annouce(void);
		void	setName(std::string name);
	
	private:
		std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif