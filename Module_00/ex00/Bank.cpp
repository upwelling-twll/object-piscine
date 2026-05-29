#include "Bank.hpp"
#include <iostream>

//Account

const Bank::Account& Bank::operator[](const int id) const
{
    std::map<int, Account*>::const_iterator it;

    it = _clientAccounts.find(id);
    if (it == _clientAccounts.end())
    {
        throw AccountException("\033[33mAccount not found");
    }
    const Account *account = it->second;
    if (!account)
    {
        throw AccountException("\033[33mAccount was deleted");
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
     : _id(id), _value(0), _loanAmount(0), _name(name), _address(address)
{

    std::cout << "Account created with ID: " << id << std::endl;
}

Bank::Account::~Account()
{
    // std::cout << "Account with ID " << this->_id << " is being destroyed." << std::endl;
}

//Bank

int Bank::addAccount(const std::string name, const std::string address)
{
    Account *newAccount = new Account(this->_nextAccountId, name, address);
    _nextAccountId++;
    _clientAccounts.insert(std::make_pair(newAccount->getId(), newAccount));

    std::cout << "Account with ID " << newAccount->getId() \
     << " added to the bank." << std::endl;
    
    return newAccount->getId();
}

void Bank::deleteAccount(const int id)
{
    std::map<int, Account*>::iterator it = _clientAccounts.find(id);

    if (it == _clientAccounts.end())
    {
        throw AccountException("\033[33mAccount not found");
    }

    delete it->second;

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
    if (amount <= 0)
    {
        throw AccountException("\033[33mInvalid deposit amount");
    }
    if (_clientAccounts.find(id) != _clientAccounts.end())
    {
        Account *account = _clientAccounts[id];
        account->_value += amount - amount * INFLOW_FEE; // Assuming a 5% fee on deposits
        this->_liquidity += amount;
        std::cout << "\033[34mDeposit of " << amount << " made to account ID " << id << "\033[0m" << std::endl;
    }
    else
    {
        throw AccountException("\033[33mAccount not found");
    }
}

void Bank::makeWithdrawal(const int id, const int amount)
{
    if (amount >= 0 && _clientAccounts.find(id) != _clientAccounts.end())
    {
        Account *account = _clientAccounts[id];
        if (account->_value >= amount) 
        {
            account->_value -= amount;
            this->_liquidity -= amount;
            std::cout << "\033[34mWithdrawal of " << amount << " made from account ID " << id << "\033[0m" << std::endl;
        }
    }
    else
    {
        throw AccountException("\033[33mAccount not found or invalid withdrawal amount");
    }
}

void Bank::processLoan(const int id, const int amount)
{
    if (amount <= 0)
    {
        throw AccountException("\033[33mInvalid loan amount");
    }
    if (this->_liquidity < amount)
    {
        throw AccountException("\033[33mInsufficient liquidity to process the loan");
    }
    if ( _clientAccounts.find(id) != _clientAccounts.end())
    {
        Account *account = _clientAccounts[id];
        account->_value += amount - amount * INFLOW_FEE; // Assuming a 5% fee on loans
        account->_loanAmount += amount;
        this->_liquidity += amount * INFLOW_FEE;
        this->_liquidity -= amount;
        std::cout << "\033[34mLoan of " << amount << " processed for account ID " << id << "\033[0m" << std::endl;
    }
    else
    {
        throw AccountException("\033[33mAccount not found");
    }
}

void Bank::getBankInformation() const
{
    std::cout << "\n\033[35mBank Liquidity: " << this->_liquidity << "\033[0m"<< std::endl;
    std::cout << "\033[32mNumber of Accounts: " << this->_clientAccounts.size() << "\033[0m\n" << std::endl;
}

Bank::Bank(int liquidity) : _liquidity(liquidity), _nextAccountId(0)
{
    if (liquidity < 0)
    {
        throw AccountException("\033[33mLiquidity cannot be negative.");
    }
    std::cout << "Bank created with liquidity: " << _liquidity << std::endl;
}

Bank::~Bank()
{
    std::cout << "Bank is being destroyed. Cleaning up resources." << std::endl;
    if (_clientAccounts.empty())
    {
        return;
    }

    std::map<int, Account*>::iterator it;
    for (it = _clientAccounts.begin(); it != _clientAccounts.end(); ++it)
    {
        if (it->second)
        {
            delete it->second;
        }
    }
    _clientAccounts.clear();
}