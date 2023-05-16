/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:21:38 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/16 20:19:34 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <time.h>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex =_nbAccounts;
	_nbAccounts += 1;
	_displayTimestamp();
	std::cout << " index:"<< _accountIndex << ";amount:"<< _amount << ";created"<<std::endl;
	
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:"<< _accountIndex << ";amount:"<< _amount << ";closed"<<std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout<<" accounts:"<<getNbAccounts()<<";total:"<< getTotalAmount()<< ";deposits:"<<getNbDeposits()<<";withdrawals:"<<getNbWithdrawals()<<std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_displayTimestamp();
	std::cout<<" index:"<<_accountIndex<<";p_amount:"<<p_amount<<";deposit:"<<deposit<<";amount:"<<_amount<<";nb_deposit:"<<_nbDeposits<<std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount = _amount;
	_displayTimestamp();
	std::cout<<" index:"<<_accountIndex<<";p_amount:"<<p_amount<<";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout<<"refused"<<std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals +=1;
	std::cout<<withdrawal<<";amount:"<< _amount<<";nb_withdrawals:"<<_nbWithdrawals<<std::endl;
	return true;
}

void Account::displayStatus() const 
{
	_displayTimestamp();
	std::cout << " index:"<< _accountIndex << ";amount:"<< _amount<< ";deposits:"<< _nbDeposits<<";withdrawals:"<<_nbWithdrawals<<std::endl;
}

void Account::_displayTimestamp()
{
	time_t		now = time(0);
	struct tm 	tstruct;
	char		buf[80];
	
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", &tstruct);
	std::cout << buf;
}

int Account::getNbAccounts()
{
	return(_nbAccounts);	
}

int Account::getTotalAmount()
{
	return(_totalAmount);
}

int Account::getNbDeposits()
{
	return(_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return(_totalNbWithdrawals);
}
