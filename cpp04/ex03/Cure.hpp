/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:27:42 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/24 20:27:09 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria {
	public:
		Cure();
		Cure(const Cure& copy);
		Cure& operator=(const Cure& copy);
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif