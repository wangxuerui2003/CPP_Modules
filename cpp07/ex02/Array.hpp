/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:43:05 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/30 17:59:37 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template<typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T>& copy);
		Array& operator=(const Array<T>& copy);
		~Array();

		unsigned int size(void) const;
		T&	operator[](unsigned int idx) const;

		class IndexOutOfRangeException : public std::exception {
			const char *what() const throw() {
				return "Index out of range";
			}
		};
	
	private:
		T	*m_arr;
		unsigned int m_size;
};

#include "Array.tpp"

#endif