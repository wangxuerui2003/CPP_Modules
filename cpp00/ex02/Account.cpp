/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:47:51 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/18 12:07:26 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* Static methods */

int	Account::getNbAccounts(void) {
	return _nbAccounts;
}

int	Account::getTotalAmount(void) {
	return _totalAmount;
}

int	Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

//accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos(void) {

	_displayTimestamp();
	std::cout 	<< "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:"
				<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}


/* Member functions */

// Constructor
Account::Account(int initial_deposit) : _amount(initial_deposit) {

	_nbAccounts++;
	_totalAmount += this->_amount;
	this->_accountIndex = _nbAccounts - 1;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// Destructor
Account::~Account() {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp(void) {

	char	formatted_time[16];
	
	time_t	now = std::time(nullptr);
	std::tm	*timeinfo = std::localtime(&now);
	std::strftime(formatted_time, 16, "%Y%m%d_%H%M%S", timeinfo);

	std::cout << '[' << formatted_time << "] ";
}

// index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit(int deposit) {

	int	p_amount = this->_amount;
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";deposit:"
				<< deposit << ";amount:" << checkAmount() << ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

// index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
// index:0;p_amount:47;withdrawal:refused
bool	Account::makeWithdrawal(int withdrawal) {

	bool	withdrawable = withdrawal <= this->_amount ? true : false;
	int		p_amount = this->_amount;

	if (withdrawable) {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
	}
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";withdrawal:";
	if (withdrawable) {
		std::cout << withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals;
	} else {
		std::cout << "refused";
	}
	std::cout << std::endl;
	return withdrawable;
}

int		Account::checkAmount(void) const {
	return this->_amount;
}

void	Account::displayStatus(void) const {

	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";amount:" << checkAmount() << ";deposits:"
				<< this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}
