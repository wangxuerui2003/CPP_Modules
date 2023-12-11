/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:11:47 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/28 13:34:43 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "data.h"
#include <sstream>
#include "colors.h"

int main(void) {
	Data *data = new Data;
	data->age = 20;
	data->name = "ray";
	data->gender = "male";
	data->from42KL = true;

	std::cout << "\t==== Before serialize ====" << std::endl;
	std::cout << "\t\tData pointer value: " << GREEN << data << RESET << std::endl;
	std::cout << "\t\tAge: " << YELLOW << data->age << RESET << std::endl;
	std::cout << "\t\tName: " << YELLOW << data->name << RESET << std::endl;
	std::cout << "\t\tGender: " << YELLOW << data->gender << RESET << std::endl;
	std::cout << "\t\tFrom42KL: " << YELLOW << data->from42KL << RESET << std::endl;

	uintptr_t	raw = Serializer::serialize(data); // unsigned long, not unsigned int *
	std::cout << std::endl;

	std::cout << "uintptr_t value:\t" << raw << std::endl;
	std::stringstream sstream;
	sstream << std::hex << raw;
	std::cout << "uintptr_t value in hex:\t" << GREEN << "0x" << sstream.str() << RESET << std::endl;

	Data *after = Serializer::deserialize(raw);
	std::cout << std::endl;

	std::cout << "\t==== Deserialize back to Data * ====" << std::endl;
	std::cout << "\t\tData pointer value: " << GREEN << after << RESET << std::endl;
	std::cout << "\t\tAge: " << YELLOW << after->age << RESET << std::endl;
	std::cout << "\t\tName: " << YELLOW << after->name << RESET << std::endl;
	std::cout << "\t\tGender: " << YELLOW << after->gender << RESET << std::endl;
	std::cout << "\t\tFrom42KL: " << YELLOW << after->from42KL << RESET << std::endl;
}