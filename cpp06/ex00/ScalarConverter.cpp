/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:35:01 by wxuerui           #+#    #+#             */
/*   Updated: 2023/08/07 16:35:31 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "colors.h"

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	*this = copy;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& copy) {
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	
}

void	ScalarConverter::convert(std::string src) {
	try {
		if (isConvertable(src)) {
			char c;
			// int i;
			// float f;
			double d;
			if (isChar(src)) {
				if (src.size() == 1) {
					c = src[0];
				} else {
					c = src[1];
				}
				display(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c), 1);
			} else {
				int precision = getPrecision(src);
				try {
					d = std::stod(src);
				} catch (std::exception& e) {
					std::cout << e.what() << std::endl;
					std::cout << RED << "All data type overflows!" << RESET << std::endl;
					return;
				}
				display(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d, precision);
			}
			
		} else {
			std::cout << RED << "Impossible to convert!" << RESET << std::endl;
		}
	} catch (ScalarConverter::PseudoLiteralsException& e) {
		convertPseudoLiterals(src);
	}
}

void ScalarConverter::display(char c, int i, float f, double d, int precision) {
	std::cout << "char: ";
	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) {
		std::cout << "impossible";
	} else if (c < 32 || c > 126) {
		std::cout << "Non displayable";
	} else {
		std::cout << '\'' << c << '\'';
	}
	std::cout << std::endl;

	std::cout << "int: ";
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
		std::cout << "impossible";
	} else {
		std::cout << i;
	}
	std::cout << std::endl;
	
	std::cout << "float: ";
	if (d < -std::numeric_limits<int>::max() || d > std::numeric_limits<float>::max()) {
		std::cout << "impossible";
	} else if (precision > 7) { // more precision than float
		std::cout << std::fixed << std::setprecision(7) << f << 'f';
	} else {
		std::cout << std::fixed << std::setprecision(precision) << f << 'f';
	}
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(precision) << "double: " << d << std::endl;
}


bool	ScalarConverter::isConvertable(std::string& src) {
	if (src.size() == 0) { // nothing
		return false;
	}
	if (isChar(src)) { // char
		return true;
	}
	if (src == "-inff" || src == "+inff" || src == "nanf"
		|| src == "-inf" || src == "+inf" || src == "nan") { // pseudo literal
		throw ScalarConverter::PseudoLiteralsException();
	}
	int dots = 0;
	for (unsigned long i = 0; i < src.size(); i++) {
		if (i == 0 && (src[i] == '-' || src[i] == '+')) {
			continue;
		} else if (i == src.size() - 1 && src[i] == 'f') {
			continue;
		} else if (src[i] == '.') {
			dots++;
			continue;
		} else if (!isdigit(src[i])) {
			return false;
		}
	}
	if (dots > 1) {
		return false;
	}
	return true;
}

bool	ScalarConverter::isChar(std::string& src) {
	return (src.size() == 1 && !isdigit(src[0])) || (src.size() == 3 && src[0] == '\'' && src[2] == '\'');
}

int		ScalarConverter::getPrecision(std::string& src) {
	int	precision;

	if (src.find('.') == std::string::npos) {
		return 1;
	}
	precision = src.size() - src.find('.') - 1;
	if (src[src.size() - 1] == 'f') {
		precision--;
	}
	if (precision < 1) {
		return 1;
	}
	return precision;
}

void ScalarConverter::convertPseudoLiterals(std::string& src) {

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	// float
	std::cout << "float: ";
	if (src.find("nan") != std::string::npos) {
		std::cout << "nanf";
	} else if (src.find('+') != std::string::npos) {
		std::cout << "+inff";
	} else {
		std::cout << "-inff";
	}
	std::cout << std::endl;

	// double
	std::cout << "double: ";
	if (src.find("nan") != std::string::npos) {
		std::cout << "nan";
	} else if (src.find('+') != std::string::npos) {
		std::cout << "+inf";
	} else {
		std::cout << "-inf";
	}
	std::cout << std::endl;
}

const char *ScalarConverter::OverflowException::what() const throw() {
	return "Overflowed in this type!";
}

const char *ScalarConverter::PseudoLiteralsException::what() const throw() {
	return "The given source string is a pseudo literal.";
}
