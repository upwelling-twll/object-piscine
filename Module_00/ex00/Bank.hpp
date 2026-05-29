#ifndef BANK_HPP
#define BANK_HPP
#include <map>
#include <iostream>
#include <exception>
#include <string>

#ifndef INFLOW_FEE
#define INFLOW_FEE 0.05
#endif

class AccountException : public std::exception
{
private:
    std::string _message;

public:

    AccountException(const std::string& message)
        : _message(message)
    {
    }

    virtual ~AccountException() throw()
    {
    }

    virtual const char* what() const throw()
    {
        return _message.c_str();
    }
};

class BankException : public std::exception
{
private:
    std::string _message;

public:

    BankException(const std::string& message)
        : _message(message)
    {
    }

    virtual ~BankException() throw()
    {
    }

    virtual const char* what() const throw()
    {
        return _message.c_str();
    }
};

class Bank 
{
private:

    //internal Account class which is only visible to the Bank
    class Account
    {
        private:
            const int   _id;
            int         _value;
            int         _loanAmount;

            std::string _name;
            std::string _address;
        
        public:

            int getId() const;
            int getValue() const;
            
            Account(int id, std::string name, std::string address);
            ~Account();

            friend class Bank; // Allow Bank to access private members of Account
    };

    int                         _liquidity;
    std::map<int, Account *>    _clientAccounts;
    int                         _nextAccountId;

    
    public:
    
    int addAccount(const std::string name, const std::string address);
    void deleteAccount(const int id);
    
    void changeAccountName(const int id, const std::string name);
    void changeAccountAddress(const int id, const std::string address);
    
    void makeDeposit(const int id, const int amount);
    void makeWithdrawal(const int id, const int amount);
    void processLoan(const int id, const int amount);
  
    const Account& operator[](const int id) const;

    void    getBankInformation() const;

    Bank(int liquidity);
    ~Bank();
};

#endif