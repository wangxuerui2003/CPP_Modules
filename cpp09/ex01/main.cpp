/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:31:48 by wxuerui           #+#    #+#             */
/*   Updated: 2023/09/11 14:02:12 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	validRPNExp(char *exp) {
	for (int i = 0; exp[i] != '\0'; ++i) {
		if (exp[i] == ' ') {
			continue;
		}

		if (exp[i + 1] != 0 && exp[i + 1] != ' ') {
			std::cerr << "Error: Error RPN format!" << std::endl;
			return false;
		} else if (!std::isdigit(exp[i]) && !isOperator(exp[i])) {
			std::cerr << "Error: Invalid character found!" << std::endl;
			return false;
		}
	}

	return true;
}

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: ./RPN \"<rpn expression>\"" << std::endl;
		return 1;
	}

	if (!validRPNExp(av[1])) {
		return 2;
	}

	RPN rpn;
	char * rpnExp = av[1];

	for (int i = 0; rpnExp[i] != '\0'; ++i) {
		if (rpnExp[i] == ' ') {
			continue;
		}

		if (std::isdigit(rpnExp[i])) {
			rpn.addOperand(rpnExp[i] - '0');
		} else {
			try {
				rpn.doOp(rpnExp[i]);
			} catch (std::exception& e) {
				std::cerr << "Error: " << e.what() << std::endl;
				return 3;
			}
		}
	}

	try {
		std::cout << rpn.getResult() << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 3;
	}
}