/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 08:53:10 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/01 17:14:05 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"

// Include all sequence containers

// #include <array> C++11
#include <vector>
// #include <forward_list> C++11
#include <list>
#include <deque>
// #include <string> // Also behave like a container, but not in STL

void	vector_test() {
	std::cout << "\n----- int Vector Test -----" << std::endl;

	std::vector<int> vector1;

	getElements<std::vector<int>, int>(vector1);

	showContainer(vector1);

	if (!vector1.empty()) {
		std::cout << "Front: " << vector1.front() << std::endl;
		std::cout << "Back: " << vector1.back() << std::endl;
		easyfind_test(vector1);
	}

}


void	deque_test() {
	std::cout << "----- int Deque Test -----" << std::endl;

	std::deque<int> deque1;

	getElements<std::deque<int>, int>(deque1);

	showContainer(deque1);

	if (!deque1.empty()) {
		std::cout << "Front: " << deque1.front() << std::endl;
		std::cout << "Back: " << deque1.back() << std::endl;
		easyfind_test(deque1);
	}

}

void	list_test() {
	std::cout << "\n----- int List Test -----" << std::endl;

	std::list<int> list1;

	getElements<std::list<int>, int>(list1);

	showContainer(list1);

	if (!list1.empty()) {
		std::cout << "Front: " << list1.front() << std::endl;
		std::cout << "Back: " << list1.back() << std::endl;
		easyfind_test(list1);
	}
}

int	main(void) {
	vector_test();
	deque_test();
	list_test();

	system("leaks -q easyfind");
}