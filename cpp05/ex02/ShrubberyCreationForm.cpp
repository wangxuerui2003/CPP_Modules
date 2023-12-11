/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:16:56 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/26 14:55:35 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Ascii tree

//        "_-_\n"
//     "/~~   ~~\\\n"
//  "/~~         ~~\\\n"
// "{               }\n"
//  "\\  _-     -_  /\n"
//    "~  \\\\ //  ~\n"
// "_- -   | | _- _\n"
//   "_ -  | |   -_\n"
//       "// \\\\\n"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy.getName(), 145, 137) {
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
	(void)copy;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	
}

void ShrubberyCreationForm::formAction(void) const {
	std::fstream outfile;

	outfile.open(getName() + std::string("_shrubbery"), std::ios::out | std::ios::trunc);
	outfile << "       _-_\n";
	outfile << "    /~~   ~~\\\n";
	outfile << " /~~         ~~\\\n";
	outfile << "{               }\n";
	outfile << " \\  _-     -_  /\n";
	outfile << "   ~  \\\\ //  ~\n";
	outfile << "_- -   | | _- _\n";
	outfile << "  _ -  | |   -_\n";
	outfile << "      // \\\\" << std::endl;

	outfile.close();
}