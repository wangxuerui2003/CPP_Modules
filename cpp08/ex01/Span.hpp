/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:20:29 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/03 13:23:37 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

class Span {
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& copy);
		Span& operator=(const Span& copy);
		~Span();

		void	addNumber(int number);
		void	addNumber(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd);

		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

		class SpanTooSmallException : public std::exception {
			const char *what() const throw();
		};

	private:
		std::vector<int> m_numbers;
		unsigned int m_capacity;
		unsigned int m_size;
};

#endif