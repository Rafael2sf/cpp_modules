/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Accounts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:47:09 by rafernan          #+#    #+#             */
/*   Updated: 2022/05/06 11:57:06 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account( int initial_deposit )
: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account() 
{
	_nbAccounts -= 1;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	std::cout << ";amount:" << _amount;
	_nbDeposits += 1;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (_amount < withdrawal)
	{
		std::cout << "index:" << _accountIndex;
		std::cout << ";p_amount:" << _amount;
		std::cout << ";withdrawal:refused\n";
		return (false);
	}
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";withdrawal:" << withdrawal;
	_amount -= withdrawal;
	std::cout << ";amount:" << _amount;
	_nbWithdrawals += 1;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus ( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
	return ;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
	return ;
}

void	Account::_displayTimestamp( void )
{
	time_t	now = time(0);
	tm		*ltm = localtime(&now);

	std::cout << '[';
	std::cout << std::setfill('0') << std::setw (4) << 1900 + ltm->tm_year;
	std::cout << std::setfill('0') << std::setw (2) << ltm->tm_mday;
	std::cout << std::setfill('0') << std::setw (2) << ltm->tm_mon;
	std::cout << '_';
	std::cout << std::setfill('0') << std::setw (2) << ltm->tm_hour;
	std::cout << std::setfill('0') << std::setw (2) << ltm->tm_min;
	std::cout << std::setfill('0') << std::setw (2) << ltm->tm_sec;
	std::cout << "] ";
	return ;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
