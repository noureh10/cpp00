/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:22:22 by nechaara          #+#    #+#             */
/*   Updated: 2024/07/16 00:49:59 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { 
	return _nbAccounts;
}
int Account::getTotalAmount(void) { 
	return _totalAmount;
}
int Account::getNbDeposits(void) { 
	return _totalNbDeposits;
}
int Account::getNbWithdrawals(void) { 
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

Account::Account(int initial_deposit) {
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	Account::_totalAmount += this->_amount;
	Account::_nbAccounts++;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created"
				<< std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->checkAmount() << ";"
				<< "closed"
				<< std::endl;
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->checkAmount() << ";"
				<< "deposit:" << deposit << ";";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout	<< "amount:" << this->checkAmount() << ";"
				<< "nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->checkAmount() << ";";
	if (this->checkAmount() < withdrawal) {
		std::cout	<< "withdrawal:refused" << std::endl;
		return false;
	} else {
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout	<< "withdrawal:" << withdrawal << ";"
					<< "amount:" << this->checkAmount() << ";"
					<< "nb_withdrawals:" << this->_nbWithdrawals
					<< std::endl;
		return true;
	}
}

int	Account::checkAmount(void) const {
	return this->_amount;
}

void	Account::displayStatus (void) const {
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->checkAmount() << ";"
				<< "deposits:" << this->_nbDeposits << ";"
				<< "withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

void Account::_displayTimestamp() {
	char timestamp[20];
	std::time_t now = std::time(NULL);
	std::tm* now_tm = std::localtime(&now);
	std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", now_tm);
	std::cout << "[" << timestamp << "] ";
}