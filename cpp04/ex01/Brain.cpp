/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:17:58 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 20:49:26 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : _currentIdeaIndex(0) {
	std::cout << "Brain constructor called." << std::endl;
}

Brain::Brain(const Brain& copy) {
	std::cout << "Brain copy constructor called." << std::endl;
	*this = copy;
}

Brain& Brain::operator=(const Brain& copy) {
	std::cout << "Brain copy assignment operator called." << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = copy._ideas[i];
	}
	this->_currentIdeaIndex = copy._currentIdeaIndex;
	
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called." << std::endl;
}

void	Brain::setIdea(std::string idea) {
	_ideas[_currentIdeaIndex] = idea;
	_currentIdeaIndex++;
}

const std::string&	Brain::getIdea(int index) const {
	if (index < 0) {
		return _ideas[0];
	} else if (index >= 100) {
		return _ideas[99];
	}
	
	return _ideas[index];
}