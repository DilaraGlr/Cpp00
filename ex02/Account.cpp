#include "Account.hpp"
#include <iostream>

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
    displayStatus();        // Affiche l'état du compte après initialisation
}

// Destructeur
Account::~Account(void) {
    _nbAccounts--;          // Décrémente le nombre total de comptes
    _totalAmount -= _amount; // Enlève le montant du compte du total global
}

// Méthode pour faire un dépôt
void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    displayStatus();  // Affiche l'état du compte après dépôt
}

// Méthode pour faire un retrait
bool Account::makeWithdrawal(int withdrawal) {
    if (_amount < withdrawal) {
        std::cout << "Withdrawal: Insufficient funds" << std::endl;
        return false; // Si le solde est insuffisant, l'opération échoue
    } else {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        displayStatus(); // Affiche l'état du compte après retrait
        return true;
    }
}

// Méthode pour vérifier le montant du compte
int Account::checkAmount(void) const {
    return _amount;
}

// Méthode pour afficher l'état du compte
void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "account:" << _accountIndex << ";amount:" << _amount << ";deposits:" 
              << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// Méthode privée pour afficher l'horodatage (timestamp)
void Account::_displayTimestamp(void) {
    // Format de l'horodatage
    std::cout << "[1992-01-04 14:54:06] "; // A adapter selon le format de l'exercice
}
