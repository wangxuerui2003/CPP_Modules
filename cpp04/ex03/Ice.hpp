/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:25:49 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/24 20:21:10 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria {
	public:
		Ice();
		Ice(const Ice& copy);
		Ice& operator=(const Ice& copy);
		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
