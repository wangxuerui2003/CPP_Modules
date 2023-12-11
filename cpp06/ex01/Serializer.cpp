/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:09:10 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/28 12:59:46 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {

}

Serializer::Serializer(const Serializer& copy) {
	*this = copy;
}

Serializer& Serializer::operator=(const Serializer& copy) {
	(void)copy;
	return *this;
}

Serializer::~Serializer() {
	
}

uintptr_t	Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}