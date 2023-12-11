/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 07:51:33 by wxuerui           #+#    #+#             */
/*   Updated: 2023/09/11 11:07:07 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string btcDB) {
	readBtcDB(btcDB);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	(void)copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
	(void)copy;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::readBtcDB(std::string btcDB) {
	std::ifstream datafile;
	std::string buffer;
	std::string strDate;
	std::string strPrice;
	size_t	commaPos;

	datafile.open(btcDB, std::ios::in);
	if (!datafile.is_open()) {
		throw std::runtime_error("Could not open data.csv");
	}

	// read the btc data
	std::getline(datafile, buffer);
	while (std::getline(datafile, buffer)) {
		commaPos = buffer.find(',');
		strDate = buffer.substr(0, commaPos);
		strPrice = buffer.substr(commaPos + 1);
		m_btcMap[dateToTimestamp(strDate)] = std::stod(strPrice);
	}

	if (m_btcMap.empty()) {
		throw std::runtime_error("data.csv is empty!");
	}

	datafile.close();
}

void	BitcoinExchange::printPriceByInput(std::string input) {
	size_t splitterPos = input.find('|');
	
	// bad input
	if (splitterPos == std::string::npos) {
		throw BadInputException();
	}

	// if there is no space in front of the '|' character
	if (input[splitterPos - 1] != ' ') {
		throw BadInputException();
	}
	std::string strDate = input.substr(0, splitterPos - 1); // exclude the trailling space
	std::string strValue = input.substr(splitterPos + 1);
	if (strValue.front() != ' ') {
		throw BadInputException();
	}

	double timestamp = dateToTimestamp(strDate);
	double value;
	try {
		value = std::stod(strValue);
	} catch (...) {
		throw BadInputException();
	}
	double price = getPriceByTimestamp(timestamp);

	if (value < 0) {
		throw NotPositiveNumberException();
	} else if (value > 1000) {
		throw TooLargeNumberException();
	}

	std::cout << strDate << " => " << value << " = " << price * value << std::endl;
}

const char *BitcoinExchange::InvalidDateException::what() const throw() {
	return "Invalid Date";
}

const char *BitcoinExchange::DateTooEarlyException::what() const throw() {
	return "Date too early";
}

const char *BitcoinExchange::BadInputException::what() const throw() {
	return "Bad Input";
}

const char *BitcoinExchange::NotPositiveNumberException::what() const throw() {
	return "Not a positive number";
}

const char *BitcoinExchange::TooLargeNumberException::what() const throw() {
	return "Too large a number";
}

double BitcoinExchange::getPriceByTimestamp(time_t timestamp) {
	if (m_btcMap.find(timestamp) != m_btcMap.end()) {
		return m_btcMap[timestamp];
	}

	// if the timestamp is even earlier than the first bitcoin record in the data map
	if (timestamp < m_btcMap.begin()->first) {
		throw DateTooEarlyException();
	}

	// iterate the map and find the nearest date to the timestamp
	std::map<time_t, double>::iterator it = m_btcMap.begin();
	while (it->first < timestamp && it != m_btcMap.end()) {
		++it;
	}

	--it; // let it be the last date that is earlier than the input timestamp

	return it->second;
}

time_t	BitcoinExchange::dateToTimestamp(std::string date) {
	// throw InvalidDateException if:
	// 1. invalid format (not yyyy-mm-dd) or contains invalid characters
	// 2. invalid date in the year and month (including not in leap year but has Feb 29th)

	if (date.length() != 10) {
		throw InvalidDateException();
	}

	for (int i = 0; i < 10; ++i) {
		if ((i == 4 || i == 7) && date[i] != '-') {
			throw InvalidDateException();
		}
		else if (i != 4 && i != 7 && !std::isdigit(date[i])) {
			throw InvalidDateException();
		}
	}

	int year, month, day;
	year = std::stoi(date.substr(0, 4));
	month = std::stoi(date.substr(5, 2));
	day = std::stoi(date.substr(8, 2));

	if (!isValidDate(year, month, day)) {
		throw InvalidDateException();
	}

	// Everything is valid, do the conversion
	struct tm t;
	std::memset(&t, 0, sizeof(struct tm));
	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = day;

	return mktime(&t);
}

void	outputError(std::string errmsg) {
	std::cerr << "Error: " << errmsg << std::endl;
}

bool isLeap(int year) {
	return (((year % 4 == 0) && 
			(year % 100 != 0)) ||
			(year % 400 == 0));
}

bool isValidDate(int y, int m, int d) {
    if (m < 1 || m > 12)
    return false;
    if (d < 1 || d > 31)
    return false;
  
    // Handle February month 
    // with leap year
    if (m == 2)
    {
        if (isLeap(y))
        	return (d <= 29);
        else
        	return (d <= 28);
    }
  
    // Months of April, June, 
    // Sept and Nov must have 
    // number of days less than
    // or equal to 30.
    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);
  
    return true;
}