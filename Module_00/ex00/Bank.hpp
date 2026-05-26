#ifndef BANK_HPP
#define BANK_HPP
#include <map>
#include <iostream>

#ifndef INFLOW_FEE
#define INFLOW_FEE 0.05

class Bank 
{
private:
    friend class Account
    {
        private:
            const int   _id;
            int         _value;
            int         _loanAmount;

            std::string _name;
            std::string _address;

        public:

            Account(int id, std::string name, std::string address);
            ~Account();
    }

    int                         _liquidity;
    std::map<int, Account *>    _clientAccounts;
    int                         _nextAccountId;

    int addAccount(const std::string name, const std::string address);
    void deleteAccount(const int id);
    
    void changeAccountName(const int id, const std::string name);
    void changeAccountAddress(const int id, const std::string address);
    
    void makeDeposit(const int id, const int amount);
    void makeWithdrawal(const int id, const int amount);
    void processLoan(const int id, const int amount);




public:

    int     getLiquidity() const;
    void    getBankInformation() const;
    void    getAccountDetails(int accountId) const;

    Bank(int liquidity);
    ~Bank();
};