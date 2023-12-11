/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:24:18 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 14:00:23 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		const std::string m_type;
		bool m_equiped;

	public:
		AMateria(std::string const & type);
		AMateria(const AMateria& copy);
		AMateria& operator=(const AMateria& copy);
		virtual ~AMateria();

		bool isEquiped(void) const;
		void setEquiped(bool equiped);
		
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif