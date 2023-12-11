/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:42:49 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 14:10:48 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "colors.h"

// Correct Base Class
class Animal {
	public:
		Animal();
		Animal(const Animal& copy);
		Animal&	operator=(const Animal& copy);
		virtual ~Animal();

		const std::string&	getType(void) const;
		virtual void	makeSound(void) const;

	protected:
		std::string	_type;
};

#endif