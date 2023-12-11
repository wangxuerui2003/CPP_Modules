/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:58:38 by wxuerui           #+#    #+#             */
/*   Updated: 2023/09/11 13:53:34 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <exception>

class RPN {
	public:
		RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& copy);
		~RPN();

		void	doOp(char op);
		void	addOperand(int num);
		int		getResult(void);

		class ErrorRPNFormat : public std::exception {
			public:
				const char *what() const throw();
		};
	
	private:
		int getNextOperand(void);
		std::stack<int> m_operands;
};

bool	isOperator(char c);

#endif