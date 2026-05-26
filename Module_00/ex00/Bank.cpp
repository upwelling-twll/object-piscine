#include "Bank.hpp"
#include <iostream>

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
    // Clean up any dynamically allocated resources if necessary
}