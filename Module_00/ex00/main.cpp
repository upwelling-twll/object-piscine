#include <iostream>
#include "Bank.hpp"

int main()
{
    Bank bank(100000); // Initialize the bank with a liquidity of 100,000

    bank.addAccount("Alice", "123 Main St");
    bank.addAccount("Bob", "456 Elm St");

    bank.makeDeposit(1, 5000);
    bank.makeDeposit(2, 3000);

    // std::cout << "Bank Liquidity: " << bank.getLiquidity() << std::endl;

    bank.makeWithdrawal(1, 2000);
    bank.processLoan(2, 10000);

    // std::cout << "Bank Liquidity after transactions: " << bank.getLiquidity() << std::endl;

    return 0;
}