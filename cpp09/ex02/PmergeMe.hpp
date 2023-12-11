/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:19:34 by wxuerui           #+#    #+#             */
/*   Updated: 2023/09/13 17:12:05 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <exception>
#include <sys/time.h>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& copy);
		~PmergeMe();

		void	mergeinsertionSortVect(std::vector<int>& vect);

		void	mergeinsertionSortList(std::list<int>& dlist);
};

int generateNextJacobNum(bool reset); // use static variables
void	outputError(std::string errMsg);

template<typename ContainerType>
void	printContainer(ContainerType& container);

template<typename ContainerType>
time_t	timeTakenToSort(PmergeMe& sorter, void (PmergeMe::*sortFunc)(ContainerType&), ContainerType& container);

template<typename ContainerType>
void	mergePairs(ContainerType& original, ContainerType& left, ContainerType& right);

template<typename ContainerType>
void	mergeSortByPairs(ContainerType& container,
	typename ContainerType::iterator begin,
	typename ContainerType::iterator end);

template<typename ContainerType>
void	binarySearchInsertion(ContainerType& container,
	typename ContainerType::iterator searchBegin,
	typename ContainerType::iterator searchEnd,
	int target);


template<typename ContainerType>
time_t	timeTakenToSort(PmergeMe& sorter, void (PmergeMe::*sortFunc)(ContainerType&), ContainerType& container) {
	struct timeval tv;
	gettimeofday(&tv, NULL);

	(sorter.*sortFunc)(container);

	struct timeval now;
	gettimeofday(&now, NULL);
	
	return now.tv_sec * 1000000L - tv.tv_sec * 1000000L + now.tv_usec - tv.tv_usec;
}

template<typename ContainerType>
void	mergePairs(ContainerType& original, ContainerType& left, ContainerType& right) {
	typename ContainerType::iterator	origIt = original.begin();
	typename ContainerType::iterator	leftIt = left.begin();
	typename ContainerType::iterator	rightIt = right.begin();

	while (leftIt != left.end() && rightIt != right.end()) {
		if (*(std::next(leftIt, 1)) < *(std::next(rightIt, 1))) {
			*(origIt++) = *(leftIt++);
			*(origIt++) = *(leftIt++);
		} else {
			*(origIt++) = *(rightIt++);
			*(origIt++) = *(rightIt++);
		}
	}

	while (leftIt != left.end()) {
		*(origIt++) = *(leftIt++);
		*(origIt++) = *(leftIt++);
	}

	while (rightIt != right.end()) {
		*(origIt++) = *(rightIt++);
		*(origIt++) = *(rightIt++);
	}
}

template<typename ContainerType>
void	mergeSortByPairs(ContainerType& container,
	typename ContainerType::iterator begin,
	typename ContainerType::iterator end) {

	size_t distance = std::distance(begin, end) / 2;
	if (distance < 2) {
		return;
	}
	
	if (distance % 2 != 0) {
		distance++;
	}
	
	typename ContainerType::iterator mid = std::next(begin, distance);
	ContainerType left(begin, mid);
	ContainerType right(mid, end);

	mergeSortByPairs(left, left.begin(), left.end());
	mergeSortByPairs(right, right.begin(), right.end());
	mergePairs(container, left, right);
}

template<typename ContainerType>
void	binarySearchInsertion(ContainerType& container,
	typename ContainerType::iterator searchBegin,
	typename ContainerType::iterator searchEnd,
	int target) {

	typename ContainerType::iterator mid;
	while (searchBegin != searchEnd) {
		mid = std::next(searchBegin, std::distance(searchBegin, searchEnd) / 2);
		if (*mid <= target && *(std::next(mid, 1)) >= target) {
			container.insert(std::next(mid, 1), target);
			return;
		} else if (*mid > target) {
			searchEnd = mid;
		} else {
			searchBegin = std::next(mid, 1);
		}
	}

	// smallest
	container.insert(searchBegin, target);
}

template<typename ContainerType>
void	printContainer(ContainerType& container) {
	int	i = INT_MAX;
	if (container.size() > 5) {
		i = 4;
	}

	typename ContainerType::iterator it;
	for (it = container.begin(); it != container.end() && i > 0; ++it) {
		std::cout << *it << ' ';
		--i;
	}

	if (it != container.end()) {
		std::cout << "[...]";
	}

	std::cout << std::endl;
}

#endif