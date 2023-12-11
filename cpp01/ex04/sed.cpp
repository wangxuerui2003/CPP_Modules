/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:38:05 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/19 19:12:10 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.h"

static void	modifyInput(std::string& input, std::string s1, std::string s2) {
	std::string::size_type	needleIndex = input.find(s1);
	
	while (needleIndex != std::string::npos) {
		input.erase(needleIndex, s1.size());
		input.insert(needleIndex, s2);
		needleIndex = input.find(s1);
	}
}

bool	sed(std::string filename, std::string s1, std::string s2) {

	std::string		buffer;
	
	std::ifstream	infile(filename, std::ios_base::in);
	if (infile.is_open() == false) {
		std::cerr << RED << "Error: Failed to open " << filename << std::endl;
		return false;
	}

	std::ofstream	outfile(filename + ".replace", std::ios_base::out | std::ios_base::trunc);
	if (outfile.is_open() == false) {
		std::cerr << RED << "Error: Failed to open " << filename + ".replace" << std::endl;
		return false;
	}

	while (std::getline(infile, buffer, '\n')) {
		modifyInput(buffer, s1, s2);
		outfile << buffer << '\n';
	}
	
	infile.close();
	outfile.close();
	return true;
}