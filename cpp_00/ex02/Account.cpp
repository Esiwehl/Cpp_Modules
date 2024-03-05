#include <ctime>
#include <iomanip>
#include <iostream>
#include "Account.hpp"

/*
Cut original log and new log timestamps out:
		< new.log cut -d " " -f2 > new_no_timestamps.log
		< 19920104_091532.log cut -d " " -f2 > old_no_timestamps.log
	Compare differences between no timestamp logs:
		diff -s old_no_timestamps.log new_no_timestamps.log
*/


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) : _accountIndex(_nbAccounts),
						_amount(0),
						_nbDeposits(0),
						_nbWithdrawals(0) {
	Account::_nbAccounts++;
	return;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
						_amount(initial_deposit),
						_nbDeposits(0),
						_nbWithdrawals(0) {
	Account::_nbAccounts++;
    Account::_totalAmount += _amount;
    _displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" <<_amount << ";"
				<< "created" << std::endl;
	return;
}

Account::~Account() {
    Account::_nbAccounts--;
    _displayTimestamp();
    std::cout   << "index" << _accountIndex << ";"
                << "amount" << _amount << ";"
                << "closed" << std::endl;
    return;
}

void Account::_displayTimestamp(){
    std::time_t rawTime;
    struct tm   *timeData;

    std::time(&rawTime);
    timeData = std::localtime(&rawTime);

    std::cout << "[" << std::put_time(timeData, "%Y%m%d_%H%M%S") << "] ";
    return;
}

int Account::getNbAccounts(){
    return Account::_nbAccounts;
}

int Account::getTotalAmount(){
    return Account::_totalAmount;
}

int Account::getNbDeposits(){
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(){
    return _totalNbWithdrawals;
}

void Account::makeDeposit(int deposit){
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    _displayTimestamp();
    std::cout   << "index:" << this->_accountIndex << ";"
                << "p_amount:" << this->_amount << ";"
                << "deposit:" << deposit << ";"
                << "amount:" << this->_amount << ";"
                << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
    _displayTimestamp();
    std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";"
				<< "withdrawal:";
	if (withdrawal > this->_amount) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	else {
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout	<< withdrawal << ";"
					<< "amount:" << this->_amount << ";"
					<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return (true);
}

int		Account::checkAmount() const {
	return (this->_amount);
}

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout	<< "index:"		<< _accountIndex << ";"
				<< "amount:"	<<_amount << ";"
				<< "deposits:"	<< _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
	return ;
}

void	Account::displayAccountsInfos(){
	_displayTimestamp();
	std::cout	<< "accounts:"	<< getNbAccounts() << ";"
				<< "total:"		<< getTotalAmount()	<< ";"
				<< "deposits:"	<< getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}