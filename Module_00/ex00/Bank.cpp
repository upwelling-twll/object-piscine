#include "Bank.hpp"
#include <iostream>

//Account

const Bank::Account& Bank::operator[](const int id) const
{
    std::map<int, Account*>::const_iterator it;

    it = _clientAccounts.find(id);
    if (it == _clientAccounts.end())
    {
        throw AccountNotFoundException("Account not found");
    }
    const Account *account = it->second;
    if (account == nullptr)
    {
        throw AccountNotFoundException("Account was deleted");
    }
    return *account;
}

int Bank::Account::getId() const
{
    return this->_id;
}

int Bank::Account::getValue() const
{
    return this->_value;
}

Bank::Account::Account(int id, std::string name, std::string address) \
     : _id(id), _name(name), _address(address), _value(0), _loanAmount(0)
{
    std::cout << "Account created with ID: " << id << std::endl;
}

Bank::Account::~Account()
{
    std::cout << "Account with ID " << this->_id << " is being destroyed." << std::endl;
}

//Bank

int Bank::addAccount(const std::string name, const std::string address)
{
    Account newAccount(this->_nextAccountId, name, address);
    _nextAccountId++;
    _clientAccounts.insert({newAccount.getId(), &newAccount});

    std::cout << "Account with ID " << newAccount.getId() \
     << " added to the bank." << std::endl;
    
     return _clientAccounts[newAccount.getId()];
}

void Bank::deleteAccount(const int id)
{
    _clientAccounts.erase(id);

    std::cout << "Account with ID " << id << " deleted from the bank." << std::endl;
}

void Bank::changeAccountName(const int id, const std::string name)
{
    if (_clientAccounts.find(id) != _clientAccounts.end())
    {
        Account *account = _clientAccounts[id];
        account->_name = name;
    }
}

void Bank::changeAccountAddress(const int id, const std::string address)
{
    if (_clientAccounts.find(id) != _clientAccounts.end())
    {
        Account *account = _clientAccounts[id];
        account->_address = address;
    }
}

void Bank::makeDeposit(const int id, const int amount)
{
    if (amount >= 0 && _clientAccounts.find(id) != _clientAccounts.end())
    {
        Account *account = _clientAccounts[id];
        account->_value += amount - amount * INFLOW_FEE; // Assuming a 5% fee on deposits
        this->_liquidity += amount;
    }
}

void Bank::makeWithdrawal(const int id, const int amount)
{
    if (amount >= 0 && _clientAccounts.find(id) != _clientAccounts.end())
    {
        Account *account = _clientAccounts[id];
        if (account->value >= amount) 
        {
            account->_value -= amount;
            this->_liquidity -= amount;
        }
    }
}

void Bank::processLoan(const int id, const int amount)
{
     if (amount >= 0 && _clientAccounts.find(id) != _clientAccounts.end() && this->_liquidity >= amount)
    {
        Account *account = _clientAccounts[id];
        account->_value += amount - amount * INFLOW_FEE; // Assuming a 5% fee on loans
        account->_loanAmount += amount;
        this->_liquidity -= amount;
    }
}

Bank::Bank(int liquidity) : liquidity(liquidity)
{
    if (liquidity < 0)
    {
        std::cerr << "Error: Liquidity cannot be negative. \
         Setting to default value." << std::endl;
        this->liquidity = 0;
    }
    std::cout << "Bank created with liquidity: " << liquidity << std::endl;
}

Bank::~Bank()
{
    std::cout << "Bank is being destroyed. Cleaning up resources." << std::endl;
    std::map<int, Account*>::iterator it;
    for (it = _clientAccounts.begin(); it != _clientAccounts.end(); ++it)
    {
        delete it->second;
    }
    _clientAccounts.clear();
}