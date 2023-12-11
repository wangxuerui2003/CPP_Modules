/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:45:48 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/31 15:06:56 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array() : m_arr(NULL), m_size(0) {
}

template<typename T>
Array<T>::Array(unsigned int n) : m_arr(new T[n]), m_size(n) {
	
}

template<typename T>
Array<T>::Array(const Array<T>& copy) : m_arr(new T[copy.size()]), m_size(copy.size()) {
	for (unsigned int i = 0; i < m_size; i++) {
		m_arr[i] = copy[i];
	}
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array<T>& copy) {
	if (m_arr != NULL) {
		delete[] m_arr;
	}
	m_size = copy.size();
	m_arr = new T[m_size];
	
	for (unsigned int i = 0; i < m_size; i++) {
		m_arr[i] = copy[i];
	}
	return *this;
}

template<typename T>
T&	Array<T>::operator[](unsigned int idx) const {
	if (idx >= m_size) {
		throw IndexOutOfRangeException();
	}
	return m_arr[idx];
}

template<typename T>
Array<T>::~Array() {
	delete[] m_arr;
}


template<typename T>
unsigned int Array<T>::size(void) const {
	return m_size;
}