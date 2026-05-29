#include <iostream>
#include "Bank.hpp"

int main()
{
    try
    {
        Bank bank(100000); 
        int id1 = bank.addAccount("Alice", "123 Main St");
        int id2 = bank.addAccount("Bob", "456 Elm St");
       
        std::cout << "\nTest deposits" << std::endl;
        bank.makeDeposit(id1, 5000);
        std::cout << "Account 1 value: " << bank[id1].getValue() << std::endl;
        bank.makeDeposit(id2, 3000);
        std::cout << "Account 1 value: " << bank[id2].getValue() << std::endl;
        
        bank.getBankInformation();
        
        std::cout << "\nTest Withdrawls and Loans" << std::endl;
        bank.makeWithdrawal(id1, 2000);
        
        bank.getBankInformation();

        bank.processLoan(id2, 1000);

        bank.getBankInformation();

        bank.deleteAccount(id1);

        bank.getBankInformation();
    }
    catch (const AccountException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
        return 0;
}
