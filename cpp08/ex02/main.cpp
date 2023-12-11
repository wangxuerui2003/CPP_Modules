/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:53:02 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/01 16:04:21 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "colors.h"

void	mstack_result() {
	std::cout << GREEN << "MutantStack result: " << RESET << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	list_result() {
	std::cout << GREEN << "\nstd::list result: " << RESET << std::endl;

	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	vector_result() {
	std::cout << GREEN << "\nstd::vector result: " << RESET << std::endl;

	std::vector<int> vector;
	vector.push_back(5);
	vector.push_back(17);
	std::cout << vector.back() << std::endl;
	vector.pop_back();
	std::cout << vector.size() << std::endl;
	vector.push_back(3);
	vector.push_back(5);
	vector.push_back(737);
	//[...]
	vector.push_back(0);
	std::vector<int>::iterator it = vector.begin();
	std::vector<int>::iterator ite = vector.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	deque_result() {
	std::cout << GREEN << "\nstd::deque result: " << RESET << std::endl;

	std::deque<int> deque;
	deque.push_back(5);
	deque.push_back(17);
	std::cout << deque.back() << std::endl;
	deque.pop_back();
	std::cout << deque.size() << std::endl;
	deque.push_back(3);
	deque.push_back(5);
	deque.push_back(737);
	//[...]
	deque.push_back(0);
	std::deque<int>::iterator it = deque.begin();
	std::deque<int>::iterator ite = deque.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	random_access_iterator_test() {
	std::cout << GREEN << "\nRandom access iterator test: " << RESET << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(5922);
	mstack.push(3);
	mstack.push(5);
	mstack.pop();
	mstack.push(737);


	for (MutantStack<int>::const_iterator it = mstack.cbegin(); it != mstack.cend(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	std::cout << "All times two" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		*it *= 2;
	}

	for (MutantStack<int>::const_iterator it = mstack.cbegin(); it != mstack.cend(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

void	different_underlying_container_test() {
	std::cout << GREEN << "\nMutantStack<int, std::list<int> > test: " << RESET << std::endl;

	MutantStack<int, std::list<int> > mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(5922);
	mstack.push(3);
	mstack.push(5);
	mstack.pop();
	mstack.push(737);
	for (MutantStack<int, std::list<int> >::const_iterator it = mstack.cbegin(); it != mstack.cend(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

void	reverse_iterator_test() {
	std::cout << GREEN << "\nReverse iterator test: " << RESET << std::endl;

	MutantStack<std::string> mstack;
	mstack.push("hi");
	mstack.push("my");
	mstack.push("name");
	mstack.push("is");
	mstack.push("ray");
	
	for (MutantStack<std::string>::const_reverse_iterator it = mstack.crbegin(); it != mstack.crend(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	std::cout << "All end by '?'" << std::endl;
	for (MutantStack<std::string>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
		*it += '?';
	}

	for (MutantStack<std::string>::const_reverse_iterator it = mstack.crbegin(); it != mstack.crend(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	mstack_result();
	list_result();
	vector_result();
	deque_result();
	random_access_iterator_test();
	different_underlying_container_test();
	reverse_iterator_test();
	return 0;
}