/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:42:53 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 21:07:48 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& copy);
		virtual ~AForm();

		const std::string& getName(void) const;
		bool isSigned(void) const;
		void beSigned(const Bureaucrat& b);
		int	getSignGrade(void) const;
		int	getExecGrade(void) const;

		static void checkGrade(int grade);

		class GradeTooHighException : public std::exception {
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			const char *what() const throw();
		};

		virtual void execute(Bureaucrat const & executor) const;
		virtual void	formAction(void) const = 0;
	
	private:
		const std::string m_name;
		bool m_signed;
		const int m_signGrade;
		const int m_executeGrade;

};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif