#include "Account.class.hpp"
#include <ctime>
#include <string>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts(void)
{
	return(Account::_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return(Account::_totalAmount);
}

int		Account::getNbDeposits(void)
{
	return(Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return(Account::_totalNbWithdrawals);
}

int		Account::checkAmount(void) const
{
	return(this->_amount);
}

Account::Account(int initial_deposit)
{
    this->_accountIndex = this->_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    this->_nbAccounts++;
    this->_totalAmount += initial_deposit;

    this->_displayTimestamp();
    std::cout
    << "index:" << this->_accountIndex
    << ";amount:" << this->_amount
    << ";created" << std::endl;
}

Account::Account(void)
{
    this->_accountIndex = this->_nbAccounts;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    this->_nbAccounts++;

    this->_displayTimestamp();
    std::cout
    << "index:" << this->_accountIndex
    << ";amount:" << this->_amount
    << ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;


    Account::_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";closed" << std::endl;
}

void	Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout
    << "index:" << this->_accountIndex
    << ";amount:" << this->_amount
    << ";deposits:" << this->_nbDeposits
    << ";withdrawals:" << this->_nbWithdrawals
    << std::endl;
}

void	Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout
    << "accounts:" << Account::_nbAccounts
    << ";total:" << Account::_totalAmount
    << ";deposits:" << Account::_totalNbDeposits
    << ";withdrawals:" << Account::_totalNbWithdrawals
    << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    const int p_amount = this->_amount;
    
    this->_nbDeposits++;
    this->_amount += deposit;

    Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;

    Account::_displayTimestamp();
    std::cout
    << "index:" << this->_accountIndex
    << ";p_amount:" << p_amount
    << ";deposit:" << deposit
    << ";amount:" << this->_amount
    << ";nb_deposits:" << this->_nbDeposits
    << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    const bool result = this->_amount >= withdrawal;
    const int p_amount = this->_amount;

    if (result)
    {
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;

        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals++;

        Account::_displayTimestamp();
        std::cout
        << "index:" << this->_accountIndex
        << ";p_amount:" << p_amount
        << ";withdrawal:" << withdrawal
        << ";amount:" << this->_amount
        << ";nb_withdrawals:" << this->_nbWithdrawals
        << std::endl;
    }
    else
    {
        Account::_displayTimestamp();
        std::cout
        << "index:" << this->_accountIndex
        << ";p_amount:" << p_amount
        << ";withdrawal:refused"
        << std::endl;
    }
    return (result);
}

void	Account::_displayTimestamp(void)
{
    std::time_t time;
    std::tm*    ftime;
    std::string str;

    time = std::time(0);
    ftime = std::localtime(&time);
    
    std::cout << "[" << ftime->tm_year + 1900;
    if (ftime->tm_mon + 1 < 10)
        std::cout << "0";
    std::cout << ftime->tm_mon + 1;
    if (ftime->tm_mday < 10)
        std::cout << "0";
    std::cout << ftime->tm_mday << "_";
    if (ftime->tm_hour < 10)
        std::cout << "0";
    std::cout << ftime->tm_hour;
    if (ftime->tm_min < 10)
        std::cout << "0";
    std::cout << ftime->tm_min;
    if (ftime->tm_sec < 10)
        std::cout << "0";
    std::cout << ftime->tm_sec << "] ";
}