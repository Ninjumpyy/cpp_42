/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:40:08 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/11 17:54:53 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor
Account::Account(void)
{
	_accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;

	_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "created\n";
}
Account::Account(int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "created\n";
}

// Destructor

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "closed\n";
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " ";
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << "\n";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:" << Account::_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	Account::_amount += deposit;
	Account::_nbDeposits++;
	_totalAmount+= deposit;
	_totalNbDeposits++;
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "nb_deposits:1\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (Account::checkAmount() >= withdrawal)
	{
		_displayTimestamp();
		std::cout << " index:" << Account::_accountIndex << ";";
		std::cout << "p_amount:" << Account::_amount << ";";
		std::cout << "withdrawal:" << withdrawal << ";";
		Account::_amount -= withdrawal;
		Account::_nbWithdrawals++;
		_totalAmount-= withdrawal;
		_totalNbWithdrawals++;
		std::cout << "amount:" << Account::_amount << ";";
		std::cout << "nb_withdrawals:1\n";
		return (true);
	}
	else
	{
		_displayTimestamp();
		std::cout << " index:" << Account::_accountIndex << ";";
		std::cout << "p_amount:" << Account::_amount << ";";
		std::cout << "withdrawal:refused\n";
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	return (Account::_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "deposits:" << Account::_nbDeposits << ";";
	std::cout << "withdrawals:" << Account::_nbWithdrawals << "\n";
}

void	Account::_displayTimestamp( void )
{
	std::time_t	current_time = std::time(NULL);
	std::tm*	local_time = std::localtime(&current_time);

	std::cout << "[";
	std::cout << (local_time->tm_year + 1900);
	if ((local_time->tm_mon + 1) < 10)
		std::cout << "0";
	std::cout << (local_time->tm_mon + 1);
	if (local_time->tm_mday < 10)
		std::cout << "0";
	std::cout << local_time->tm_mday;
	std::cout << "_";
	if (local_time->tm_hour < 10)
		std::cout << "0";
	std::cout << local_time->tm_hour;
	if (local_time->tm_min < 10)
		std::cout << "0";
	std::cout << local_time->tm_min;
	if (local_time->tm_sec < 10)
		std::cout << "0";
	std::cout << local_time->tm_sec;
	std::cout << "]";
}
