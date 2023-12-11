/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:19:06 by wxuerui           #+#    #+#             */
/*   Updated: 2023/09/13 17:06:59 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac < 2) {
		outputError("Usage: ./PmergeMe <positive integers>");
		return 1;
	}

	int size = ac - 1;
	std::vector<int> vect(size);
	std::list<int> dlist;

	for (int i = 1; i < ac; ++i) {
		int num;
		try {
			num = std::stoi(av[i]);
			vect[i - 1] = num;
			dlist.push_back(num);
		} catch (std::invalid_argument&) {
			outputError("Non-number arguments detected!");
			return 2;
		} catch (std::out_of_range&) {
			outputError("Input number bigger than max int!");
			return 3;
		}
		if (num <= 0) {
			outputError("All input numbers should be positive integers!");
			return 4;
		}
	}

	PmergeMe sorter;

	std::cout << "Vect Before:\t"; printContainer(vect);
	std::cout << "DList Before:\t"; printContainer(dlist);
	time_t	vectSortTime = timeTakenToSort<std::vector<int> >(sorter, &PmergeMe::mergeinsertionSortVect, vect);
	time_t	dlistSortTime = timeTakenToSort<std::list<int> >(sorter, &PmergeMe::mergeinsertionSortList, dlist);
	std::cout << "Vect After:\t"; printContainer(vect);
	std::cout << "DList After:\t"; printContainer(dlist);
	std::cout << "Vect is sorted: " << (std::is_sorted(vect.begin(), vect.end()) ? "true" : "false") << std::endl;
	std::cout << "Dlist is sorted: " << (std::is_sorted(dlist.begin(), dlist.end()) ? "true" : "false") << std::endl;
	std::cout << "Time to process a range of " << vect.size() << " elements with std::vector:\t" << vectSortTime << " us" << std::endl;
	std::cout << "Time to process a range of " << dlist.size() << " elements with std::list:\t" << dlistSortTime << " us" << std::endl;
}