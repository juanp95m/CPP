#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
			<< ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" 
			<< this->_amount << ";closed" << std::endl;
	this->_nbAccounts--;
	_totalAmount -= this->_amount;
}


int Account::getNbAccounts(){
	return (_nbAccounts);
}
int Account::getNbDeposits(){
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(){
	return (_totalNbWithdrawals);
}

int Account::getTotalAmount(){
	return (_totalAmount);
}

void Account::displayAccountsInfos(){
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount 
			<< ";deposits:" << _totalNbDeposits 
			<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(){
	std::time_t	finalTime = time(NULL);
	std::tm *tme = std::localtime(&finalTime);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", tme);
	std::cout << buffer << " ";
}

void Account::displayStatus() const{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount 
			<< ";deposits:" << _nbDeposits 
			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}


void Account::makeDeposit(int deposit){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";deposit:" << deposit;

	this->_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";amount:" << this->_amount 
			<< ";nb_deposits:" << this->_nbDeposits
			<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;

	if (withdrawal > this->_amount){
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else{
		std::cout << ";withdrawal:" << withdrawal;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;

		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;

		std::cout << ";amount:" << _amount 
				<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return (true);
}
