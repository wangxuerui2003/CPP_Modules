/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:19:28 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/31 19:07:13 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <vector>
// #include <algorithm>
// #include <iterator>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack() : std::stack<T, Container>() {}
		MutantStack(const MutantStack<T, Container>& copy) : std::stack<T, Container>(copy) {}
		MutantStack& operator=(const MutantStack<T>& copy) {
			this->c = copy.c;
			return *this;
		}
		~MutantStack() {}

		typedef typename std::stack<T, Container>::container_type::iterator	iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator	const_iterator;
		typedef typename std::stack<T, Container>::container_type::reverse_iterator	reverse_iterator;
		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator	begin(void) { return this->c.begin(); }
		iterator	end(void) { return this->c.end(); }
		const_iterator	cbegin(void) { return this->c.cbegin(); }
		const_iterator	cend(void) { return this->c.cend(); }
		reverse_iterator	rbegin(void) { return this->c.rbegin(); }
		reverse_iterator	rend(void) { return this->c.rend(); }
		const_reverse_iterator	crbegin(void) { return this->c.crbegin(); }
		const_reverse_iterator	crend(void) { return this->c.crend(); }
};

#endif