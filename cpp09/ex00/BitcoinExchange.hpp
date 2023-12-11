/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:16:35 by wxuerui           #+#    #+#             */
/*   Updated: 2023/09/11 13:24:48 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <map>
#include <algorithm>
#include <ctime>

class BitcoinExchange {
	public:
		BitcoinExchange(std::string btcDB);
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		~BitcoinExchange();

		void printPriceByInput(std::string input); // called by outside of class
	
		class InvalidDateException : public std::exception {
			public:
				const char *what() const throw();
		};

		class DateTooEarlyException : public std::exception {
			public:
				const char *what() const throw();
		};

		class BadInputException : public std::exception {
			public:
				const char *what() const throw();
		};

		class NotPositiveNumberException : public std::exception {
			public:
				const char *what() const throw();
		};

		class TooLargeNumberException : public std::exception {
			public:
				const char *what() const throw();
		};

	private:
		void	readBtcDB(std::string btcDB); // deserialize all date->price pairs from the database file
		double getPriceByTimestamp(time_t timestamp); // returns the corresponding bitcoin price by passing in a timestamp
		time_t	dateToTimestamp(std::string date); // might throw the InvalidDateException 

		std::map<time_t, double> m_btcMap; // pointer to a map storing the bitcoins date and value pairs
};



void	outputError(std::string errmsg);
bool	isValidDate(int d, int m, int y);

#endif