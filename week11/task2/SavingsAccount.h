#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"

class SavingsAccount : public BankAccount
{
private:
    double interestRate;
    int monthsActive;

public:
    SavingsAccount(std::string owner, std::string iban, double initialBalance, double interestRate);

    double getInterestRate() const;
    int getMonthsActive() const;
    void applyMonthlyInterest();
    void displayInfo() const override;
};

#endif