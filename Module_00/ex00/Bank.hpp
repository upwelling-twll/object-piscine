#ifndef BANK_HPP
#define BANK_HPP

class Bank 
{
private:
    int liquidity;
    std::map<int, Account *> _clientAccounts;
        
    void addAccount(Account *account);
    void deleteAccount(Account *account);
    
    void modifyAccount(enum property, std::string value);
    
    void makeDeposit(Account *account, int amount);
    void makeWithdrawal(Account *account, int amount);
    void giveLoan(Account *account, int amount);
    
public:

    int getLiquidity() const;
    void getBankInformation() const;
    void getAccountDetails(int accountId) const;

    Bank(int liquidity);
    ~Bank();
};