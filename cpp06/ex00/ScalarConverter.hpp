/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:28:31 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/28 13:32:39 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <iomanip>
#include <limits>

class ScalarConverter {
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& copy);
	~ScalarConverter();
	
	public:
		static void convert(std::string src);
		static bool isChar(std::string& src);
		static int getPrecision(std::string& src);
		static bool isConvertable(std::string& src);
		static void convertPseudoLiterals(std::string& src);
		static void display(char c, int i, float f, double d, int precision);

		class OverflowException : std::exception {
			const char *what() const throw();
		};

		class PseudoLiteralsException : std::exception {
			const char *what() const throw();
		};
};

#endif