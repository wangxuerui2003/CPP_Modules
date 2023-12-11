/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:30:14 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 14:11:40 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#include "colors.h"

// Wrong Base Class
class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal&	operator=(const WrongAnimal& copy);
		virtual ~WrongAnimal();

		const std::string&	getType(void) const;
		void	makeSound(void) const;

	protected:
		std::string	_type;
};

#endif