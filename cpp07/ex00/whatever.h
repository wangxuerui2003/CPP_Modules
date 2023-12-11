/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:38:46 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/27 20:50:39 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

#include <iostream>
#include <string>

template<typename T>
void	swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T&	min(T&a, T& b) {
	return (a < b ? a : b);
}

template<typename T>
T&	max(T&a, T& b) {
	return (a > b ? a : b);
}

#endif