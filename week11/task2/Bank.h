#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include <optional>
#include "SavingsAccount.h"
#include "CreditAccount.h"

class Bank
{
private:
    std::string bankName;
    std::vector<SavingsAccount> savingsAccounts;
    std::vector<CreditAccount> creditAccounts;

public:
    Bank(std::string bankName);

    void openSavings(const SavingsAccount &acc);
    void openCredit(const CreditAccount &acc);
    void closeByIban(const std::string &iban);
    void applyAllMonthlyInterest();
    void applyAllMonthlyFees();
    std::vector<CreditAccount> getOverdueAccounts() const;
    std::optional<SavingsAccount> findRichest() const;
    double totalDebt() const;

    explicit operator bool() const;
};

#endif