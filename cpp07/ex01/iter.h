/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:54:58 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/28 13:40:58 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

#include <iostream>
#include <string>

template<typename ArrType, typename FuncType>
void	iter(ArrType *arr, int len, FuncType iterFunc) {
	if (arr == NULL || len <= 0 || iterFunc == NULL) {
		return;
	}
	for (int i = 0; i < len; ++i) {
		iterFunc(arr[i]);
	}
}

// Testing function templates

template<typename T>
void	output(T const src) {
	std::cout << src << std::endl;
}

template<typename T>
void	doubleit(T& src) {
	src *= 2;
}

#endif