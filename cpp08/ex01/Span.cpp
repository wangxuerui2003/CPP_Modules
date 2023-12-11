/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:32:11 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/03 13:23:29 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : m_capacity(0), m_size(0) {
	
}

Span::Span(unsigned int n) : m_capacity(n), m_size(0) {
	
}

Span::Span(const Span& copy) {
	*this = copy;
}

Span& Span::operator=(const Span& copy) {
	m_capacity = copy.m_capacity;
	m_size = copy.m_size;
	m_numbers = copy.m_numbers;
	return *this;
}

Span::~Span() {

}

void	Span::addNumber(int number) {
	if (m_size >= m_capacity) {
		throw SpanTooSmallException();
	}
	m_numbers.push_back(number);
	m_size++;
}

void	Span::addNumber(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd) {
	int distance = std::distance(itBegin, itEnd);
	if (distance <= 0) {
		return;
	}
	m_numbers.insert(m_numbers.end(), itBegin, itEnd);
	if (m_numbers.size() > m_capacity) {
		m_numbers.resize(m_capacity);
		m_size = m_capacity;
		throw SpanTooSmallException();
	}
	m_size = m_numbers.size();
}

unsigned int	Span::shortestSpan(void) {
	if (m_size < 2) {
		throw SpanTooSmallException();
	}
	std::vector<int> forTransform(m_numbers.size() - 1);
	std::vector<unsigned int> result(m_numbers.size() - 1);

	std::sort(m_numbers.begin(), m_numbers.end());
	std::copy(m_numbers.begin() + 1, m_numbers.end(), forTransform.begin());
	std::transform(forTransform.begin(), forTransform.end(), m_numbers.begin(), result.begin(), std::minus<long>());

	return *std::min_element(result.begin(), result.end());
}

unsigned int	Span::longestSpan(void) {
	if (m_size < 2) {
		throw SpanTooSmallException();
	}
	return (unsigned int)*std::max_element(m_numbers.begin(), m_numbers.end()) - (unsigned int)*std::min_element(m_numbers.begin(), m_numbers.end());
}

const char *Span::SpanTooSmallException::what() const throw() {
	return "The Span is too small!";
}