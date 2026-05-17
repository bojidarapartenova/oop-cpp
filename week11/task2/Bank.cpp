#include "Bank.h"
#include <iostream>

Bank::Bank(std::string bankName) : bankName(bankName) {}

void Bank::openSavings(const SavingsAccount &acc)
{
    savingsAccounts.push_back(acc);
}

void Bank::openCredit(const CreditAccount &acc)
{
    creditAccounts.push_back(acc);
}

void Bank::closeByIban(const std::string &iban)
{
    std::erase_if(savingsAccounts, [&iban](const SavingsAccount sa)
                  { return sa.getIban() == iban; });

    std::erase_if(creditAccounts, [&iban](const CreditAccount ca)
                  { return ca.getIban() == iban; });
}

void Bank::applyAllMonthlyInterest()
{
    for (SavingsAccount &sa : savingsAccounts)
    {
        sa.applyMonthlyInterest();
    }
}

void Bank::applyAllMonthlyFees()
{
    for (CreditAccount &ca : creditAccounts)
    {
        ca.applyMonthlyFee();
    }
}

std::vector<CreditAccount> Bank::getOverdueAccounts() const
{
    std::vector<CreditAccount> result;
    for (size_t i = 0; i < creditAccounts.size(); i++)
    {
        if (creditAccounts[i].isOverdue())
        {
            result.push_back(creditAccounts[i]);
        }
    }
    return result;
}

std::optional<SavingsAccount> Bank::findRichest() const
{
    if (savingsAccounts.empty())
    {
        return std::nullopt;
    }

    const SavingsAccount *richest = &savingsAccounts[0];
    for (size_t i = 0; i < savingsAccounts.size(); i++)
    {
        if (savingsAccounts[i].getBalance() > richest->getBalance())
        {
            richest = &savingsAccounts[i];
        }
    }
    return *richest;
}

double Bank::totalDebt() const
{
    double sum = 0;
    for (size_t i = 0; i < creditAccounts.size(); i++)
    {
        sum += creditAccounts[i].getDebtAmount();
    }
    return sum;
}

Bank::operator bool() const
{
    return savingsAccounts.size() > 0 || creditAccounts.size() > 0;
}
