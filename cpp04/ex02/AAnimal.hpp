/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:42:49 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 14:12:23 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"
#include "colors.h"

class AAnimal {
	public:
		AAnimal();
		AAnimal(const AAnimal& copy);
		AAnimal&	operator=(const AAnimal& copy);
		virtual ~AAnimal();

		const std::string&	getType(void) const;
		void	setIdea(std::string idea);
		const std::string&	getIdea(int index) const;
		virtual void	makeSound(void) const = 0; // Pure virtual function

	protected:
		std::string	_type;
		Brain	*_brain;
};

#endif