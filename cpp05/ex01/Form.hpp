/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:42:53 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/27 13:21:40 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form& copy);
		Form& operator=(const Form& copy);
		~Form();

		const std::string& getName(void) const;
		bool isSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		void beSigned(const Bureaucrat& b);

		static void checkGrade(int grade);

		class GradeTooHighException : public std::exception {
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};
	
	private:
		const std::string m_name;
		bool m_signed;
		const int m_signGrade;
		const int m_executeGrade;

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif