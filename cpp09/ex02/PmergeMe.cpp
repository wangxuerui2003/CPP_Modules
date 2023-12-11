/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:31:44 by wxuerui           #+#    #+#             */
/*   Updated: 2023/09/13 16:18:02 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	(void)copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
	(void)copy;
	return *this;
}

PmergeMe::~PmergeMe() {}

/**
 * TODO: split into pairs of 2 elements, leftovers are now ignored
 * TODO: sort the pairs of 2 elements into [s, l], [s, l] ...
 * TODO: recursively sort (merge sort) the pairs based on the l values
 * TODO: then use the first (smallest) s value and the list of l values as the main chain
 * 			and the rest of the s values as the pend chain
 * TODO: Use the Jacobsthal number to determine the pend numbers that are inserted into the main chain.
 * 			When Jacobsthal number is too large, then use a for loop to insert the rest of the pend into main chain.
 * 			Note that the insertion sort used is the binary-insertion method since main chain is sorted
 * 			The range of binary search is only up to the l number that is in the same pair of the current inserting s number,
 * 				since all the numbers after it are confirm bigger
 * 
*/
void	PmergeMe::mergeinsertionSortVect(std::vector<int>& vect) {
	if (vect.size() == 1) {
		return;
	}

	std::vector<int>::iterator	leftoverIt = vect.begin();
	while (leftoverIt + 1 < vect.end()) {
		leftoverIt += 2;
	}

	for (std::vector<int>::iterator it = vect.begin(); it < leftoverIt; it += 2) {
		if (*it > *(it + 1)) {
			std::swap(*it, *(it + 1));
		}
	}

	mergeSortByPairs(vect, vect.begin(), leftoverIt);

	// main chain
	// pend chain
	// binary insertion sort

	std::vector<int> pendChain;
	std::vector<int> mainChain;
	mainChain.reserve(vect.size());
	pendChain.reserve(vect.size() / 2 - 1);
	mainChain.push_back(vect[0]);
	mainChain.push_back(vect[1]);
	
	for (std::vector<int>::iterator it = vect.begin() + 2; it < leftoverIt; it += 2) {
		pendChain.push_back(*it);
		mainChain.push_back(*(it + 1));
	}

	int pendNumsCount = pendChain.size();
	int i = 0;
	generateNextJacobNum(true); // reset
	while (i < pendNumsCount) {
		size_t index = generateNextJacobNum(false) - 1;
		if (index < pendChain.size()) {
			binarySearchInsertion<std::vector<int> >(mainChain, mainChain.begin(), mainChain.begin() + 2 + index + i, pendChain[index]);
			++i;
		}
	}

	// insert leftover if any
	if (leftoverIt != vect.end()) {
		binarySearchInsertion<std::vector<int> >(mainChain, mainChain.begin(), mainChain.end(), *leftoverIt);
	}

	vect = mainChain;
}

/**
 * TODO:
*/
void	PmergeMe::mergeinsertionSortList(std::list<int>& dlist) {
	if (dlist.size() == 1) {
		return;
	}

	std::list<int>::iterator	leftoverIt = dlist.begin();
	while (leftoverIt != dlist.end() && std::next(leftoverIt, 1) != dlist.end()) {
		std::advance(leftoverIt, 2);
	}

	for (std::list<int>::iterator it = dlist.begin(); it != leftoverIt; std::advance(it, 2)) {
		if (*it > *(std::next(it, 1))) {
			std::swap(*it, *(std::next(it, 1)));
			// std::rotate(std::next(it, -1), std::next(it, 1), std::next(it, 2));
		}
	}

	mergeSortByPairs(dlist, dlist.begin(), leftoverIt);

	// main chain
	// pend chain
	// binary insertion sort

	std::list<int> pendChain;
	std::list<int> mainChain;
	std::list<int>::iterator it = dlist.begin();
	mainChain.push_back(*(it++));
	mainChain.push_back(*(it++));
	
	while (it != leftoverIt) {
		pendChain.push_back(*(it++));
		mainChain.push_back(*(it++));
	}

	int pendNumsCount = pendChain.size();
	int i = 0;
	generateNextJacobNum(true); // reset
	size_t index;
	while (i < pendNumsCount) {
		index = generateNextJacobNum(false) - 1;
		if (index < pendChain.size()) {
			it = std::next(pendChain.begin(), index);
			binarySearchInsertion<std::list<int> >(mainChain, mainChain.begin(), std::next(mainChain.begin(), 2 + index + i), *it);
			++i;
		}
	}

	// insert leftover if any
	if (leftoverIt != dlist.end()) {
		binarySearchInsertion<std::list<int> >(mainChain, mainChain.begin(), mainChain.end(), *leftoverIt);
	}

	dlist = mainChain;
}

// ignore the 0, 1 in the beginning of the series
// 1 3 2 5 4 11 10 9 8 7 6 21 20 19 18...
int generateNextJacobNum(bool reset) {
	static int curr = 1; // nth element in jacobsthal series
	static int curr_1 = 1; // n-1th element in jacobsthal series
	static int jacobNum = curr;

	if (reset) {
		curr = 1;
		curr_1 = 1;
		jacobNum = curr;
		return 1;
	}

	int ret = jacobNum;

	jacobNum--;
	if (jacobNum <= curr_1) {
		int temp = curr;
		curr = curr_1 * 2 + curr;
		curr_1 = temp;
		jacobNum = curr;
	}

	return ret;
}

void outputError(std::string errMsg) {
	std::cerr << "Error: " << errMsg << std::endl;
}
