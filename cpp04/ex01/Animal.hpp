/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:42:49 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 20:55:02 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "colors.h"
#include "Brain.hpp"

// Correct Base Class
class Animal {
	public:
		Animal();
		Animal(const Animal& copy);
		Animal&	operator=(const Animal& copy);
		virtual ~Animal();

		const std::string&	getType(void) const;
		virtual void	makeSound(void) const;
		virtual void	setIdea(std::string idea) = 0;
		virtual const std::string&	getIdea(int index) const = 0;

	protected:
		std::string	_type;
};

#endif