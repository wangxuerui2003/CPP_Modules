/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:51:19 by wxuerui           #+#    #+#             */
/*   Updated: 2023/09/11 11:08:22 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		outputError("could not open file.");
		return 1;
	} else if (ac > 2) {
		outputError("too many files!");
		return 2;
	}

	std::ifstream inputFile;
	inputFile.open(av[1], std::ios::in);
	if (!inputFile.is_open()) {
		outputError("could not open file.");
		return 3;
	}
	
	try {
		BitcoinExchange btc("data.csv"); // might throw the InvalidDateException if got error in data.csv
		std::string buffer;
		std::getline(inputFile, buffer); // ignore the header of the csv file
		while (std::getline(inputFile, buffer)) {
			try {
				btc.printPriceByInput(buffer);
			} catch (BitcoinExchange::InvalidDateException&) {
				outputError("invalid date.");
			} catch (BitcoinExchange::DateTooEarlyException&) {
				outputError("date is too early.");
			} catch (BitcoinExchange::BadInputException&) {
				outputError("bad input => " + buffer);
			} catch (BitcoinExchange::NotPositiveNumberException&) {
				outputError("not a positive number.");
			} catch (BitcoinExchange::TooLargeNumberException&) {
				outputError("too large a number.");
			}
		}
	} catch (BitcoinExchange::InvalidDateException&) {
		outputError("invalid date exists in data.csv");
	} catch (std::runtime_error& e) {
		outputError(e.what());
	}


	inputFile.close();

	return 0;
}