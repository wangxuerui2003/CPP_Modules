/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:55:53 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/30 18:04:09 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"

int main(void) {
	{
		std::cout << "--------------------" << std::endl;
		int arr[5] = {1, 2, 3, 4, 5};
		iter(arr, 5, output<int>);
		// iter<int, void(*)(int)>(arr, 5, output);
		std::cout << "--------------------" << std::endl;
	}

	{
		std::cout << "--------------------" << std::endl;
		std::string arr[5] = {"a", "b", "c", "d", "e"};
		iter(arr, 5, output<std::string>);
		std::cout << "--------------------" << std::endl;
	}
	{
		std::cout << "--------------------" << std::endl;
		int arr[5] = {1, 2, 3, 4, 5};
		iter(arr, 5, doubleit<int>);
		for (int i = 0; i < 5; i++) {
			std::cout << arr[i] << std::endl;
		}
		std::cout << "--------------------" << std::endl;
	}
}