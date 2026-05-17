#include "CreditAccount.h"
#include <iostream>

CreditAccount::CreditAccount(std::string owner, std::string iban, double creditLimit, double monthlyFeeRate) : BankAccount(owner, iban, 0), creditLimit(creditLimit), debtAmount(0), monthlyFeeRate(monthlyFeeRate) {}

double CreditAccount::getCreditLimit() const
{
    return creditLimit;
}

double CreditAccount::getDebtAmount() const
{
    return debtAmount;
}

double CreditAccount::getAvailableCredit() const
{
    return creditLimit - debtAmount;
}

bool CreditAccount::borrow(double amount)
{
    if (amount > 0 && amount <= getAvailableCredit())
    {
        debtAmount += amount;
        transactionHistory.push_back("Borrowed: " + std::to_string(amount));
        return true;
    }
    return false;
}

void CreditAccount::repay(double amount)
{
    debtAmount -= amount;
    if (debtAmount < 0)
    {
        debtAmount = 0;
    }
    transactionHistory.push_back("Repaid: " + std::to_string(amount));
}

void CreditAccount::applyMonthlyFee()
{
    debtAmount += debtAmount * monthlyFeeRate;
    transactionHistory.push_back("Monthly Fee Applied: " + std::to_string(debtAmount * monthlyFeeRate));
}

bool CreditAccount::isOverdue() const
{
    return debtAmount > (creditLimit * 0.9);
}

void CreditAccount::displayInfo() const
{
    BankAccount::displayInfo();
    std::cout << creditLimit << " " << debtAmount << " " << monthlyFeeRate << "\n";
}
