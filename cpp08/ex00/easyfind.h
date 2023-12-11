/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:41:59 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/01 17:14:08 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

#include <algorithm>
#include <string>
#include <iostream>

template<typename T>
typename T::iterator	easyfind(T& container, int i) {
	return std::find(container.begin(), container.end(), i);
}

template<typename TypeContainer, typename TypeData>
void	getElements(TypeContainer& container) {
	char		option;
	TypeData	data;

	std::cout << "Format: <option y/q> <data>" << std::endl;
	std::cout << ">>>: ";
	while (std::cin >> option) {
		if (option == 'q') {
			return;
		}
		std::cin >> data;
		container.push_back(data);
		std::cout << ">>>: ";
	}
}

template<typename TypeContainer>
void	showContainer(TypeContainer& container) {
	std::cout << "--------------------" << std::endl;
	for (typename TypeContainer::const_iterator it = container.cbegin(); it != container.cend(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << "--------------------" << std::endl;
}

template<typename TypeContainer>
void	easyfind_test(TypeContainer& container) {
	char mode;
	int data;
	typename TypeContainer::iterator pos;

	std::cout << "Find the index of an element." << std::endl;
	std::cout << "Format: <option y/q> <data>" << std::endl;
	std::cout << ">>>: ";
	while (std::cin >> mode) {
		if (mode == 'q') {
			return;
		}
		std::cin >> data;
		pos = easyfind(container, data);
		if (pos != container.end()) {
			std::cout << "Element is at index " << (int)std::distance(container.begin(), pos) << std::endl;
		} else {
			std::cout << "Element does not exist!" << std::endl;
		}
		std::cout << ">>>: ";
	}
}


#endif