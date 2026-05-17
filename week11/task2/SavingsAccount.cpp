#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(std::string owner, std::string iban, double initialBalance, double interestRate) : BankAccount(owner, iban, initialBalance), interestRate(interestRate), monthsActive(0) {}

double SavingsAccount::getInterestRate() const
{
    return interestRate;
}

int SavingsAccount::getMonthsActive() const
{
    return monthsActive;
}

void SavingsAccount::applyMonthlyInterest()
{
    double interest = balance * interestRate / 12.0;
    balance += interest;
    monthsActive++;
    transactionHistory.push_back("Interest Applied: +" + std::to_string(interest));
}

void SavingsAccount::displayInfo() const
{
    BankAccount::displayInfo();
    std::cout << interestRate << " " << monthsActive << "\n";
}
