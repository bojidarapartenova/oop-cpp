#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount
{
private:
    std::string accountNumber;
    std::string ownerName;
    double balance;
    bool isFrozen;

public:
    BankAccount(std::string accNumber, std::string owner, double initialBalance);

    void deposit(double amount);
    void withdraw(double amount);
    void transfer(BankAccount &destination, double amount);
    void freeze();
    void unfreeze();
    void processTransaction(BankAccount &from, BankAccount &to, double amount);
};

#endif