/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:28:50 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 17:13:39 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"
#include "colors.h"

class Form;

class Bureaucrat {
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();

		const std::string& getName(void) const;
		int 	getGrade(void) const;
		void	incGrade(void);
		void	decGrade(void);

		static void	checkGrade(int grade); // throw corresponding exception if grade not in valid range

		void signForm(Form& form);
		
		class GradeTooHighException : public std::exception {
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};

	private:
		const std::string m_name;
		int m_grade; // highest 1, lowest 150
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src);

#endif