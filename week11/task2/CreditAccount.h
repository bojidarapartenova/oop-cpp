#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

#include "BankAccount.h"

class CreditAccount : public BankAccount
{
private:
    double creditLimit;
    double debtAmount;
    double monthlyFeeRate;

public:
    CreditAccount(std::string owner, std::string iban, double creditLimit, double monthlyFeeRate);

    double getCreditLimit() const;
    double getDebtAmount() const;
    double getAvailableCredit() const;
    bool borrow(double amount);
    void repay(double amount);
    void applyMonthlyFee();
    bool isOverdue() const;
    void displayInfo() const override;
};

#endif