/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:08:26 by wxuerui           #+#    #+#             */
/*   Updated: 2023/09/11 14:10:48 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy) {
	(void)copy;
}

RPN&	RPN::operator=(const RPN& copy) {
	(void)copy;
	return *this;
}

RPN::~RPN() {}

void RPN::doOp(char op) {
	long left, right, result;
	
	right = getNextOperand();
	left = getNextOperand();

	if (op == '+') {
		result = left + right;
	} else if (op == '-') {
		result = left - right;
	} else if (op == '*') {
		result = left * right;
	} else {
		if (right == 0) {
			throw std::runtime_error("Division by zero!");
		}
		result = left / right;
	}

	if (result > INT_MAX) {
		throw std::overflow_error("Integer overflowed!");
	} else if (result < INT_MIN) {
		throw std::underflow_error("Integer underflowed!");
	}

	addOperand(result);
}

void	RPN::addOperand(int num) {
	m_operands.push(num);
}

int RPN::getNextOperand(void) {
	if (m_operands.empty()) {
		throw ErrorRPNFormat();
	}

	int nextOperand = m_operands.top();
	m_operands.pop();

	return nextOperand;
}

int		RPN::getResult(void) {
	if (m_operands.size() != 1) {
		throw ErrorRPNFormat();
	}
	return m_operands.top();
}

const char *RPN::ErrorRPNFormat::what() const throw() {
	return "Error RPN format!";
}

bool	isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}