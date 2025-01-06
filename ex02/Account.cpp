#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

// Initialisation des variables statiques
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Méthode statique : retourne le nombre total de comptes
int Account::getNbAccounts(void) {
    return _nbAccounts;
}

// Méthode statique : retourne le montant total des comptes
int Account::getTotalAmount(void) {
    return _totalAmount;
}

// Méthode statique : retourne le nombre total de dépôts
int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

// Méthode statique : retourne le nombre total de retraits
int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

// Méthode statique : affiche les informations globales des comptes
void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" 
              << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Constructeur
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts++;          // Augmente le nombre total de comptes
    _totalAmount += initial_deposit; // Ajoute le montant du dépôt initial au total global
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";created" << std::endl;
}

// Destructeur
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// Méthode pour faire un dépôt
void Account::makeDeposit(int deposit) {
    _displayTimestamp();
	this->_nbDeposits++;
	std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "deposit:" << deposit << ";amount:" << _amount
					+ deposit << ";nb_deposits:" << this->_nbDeposits << std::endl;
    this->_amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

// Méthode pour faire un retrait
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "withdrawal:" << withdrawal << ";";
    if (checkAmount() < withdrawal) {
        std::cout << "withdrawal:refused" << std::endl;
        return false; // Si le solde est insuffisant, l'opération échoue
    }
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
	    std::cout << withdrawal << ":amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
}

// Méthode pour vérifier le montant du compte
int Account::checkAmount(void) const {
    return _amount;
}

// Méthode pour afficher l'état du compte
void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
     << ";p_amount:" << _amount 
     << ";deposits:" << _nbDeposits 
     << ";withdrawals:" << _nbWithdrawals
    << std::endl;
}

// Méthode privée pour afficher l'horodatage (timestamp)
void Account::_displayTimestamp(void) {
    // Format de l'horodatage
std::cout << std::setfill('0') << "[";
	std::time_t now = std::time(0);
	std::tm *local_time = std::localtime(&now);
	std::cout << 1900 + local_time->tm_year;
	std::cout << std::setw(2) << 1 + local_time->tm_mon;
	std::cout << std::setw(2) << local_time->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << local_time->tm_hour;
	std::cout << std::setw(2) << local_time->tm_min;
	std::cout << std::setw(2) << local_time->tm_sec;
	std::cout << std::setw(2) << "] ";
}
