#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(std::string owner, std::string iban, double initialBalance) : owner(owner), iban(iban), balance(initialBalance) {}

const std::string &BankAccount::getOwner() const
{
    return owner;
}

const std::string &BankAccount::getIban() const
{
    return iban;
}

double BankAccount::getBalance() const
{
    return balance;
}

const std::vector<std::string> &BankAccount::getHistory() const
{
    return transactionHistory;
}

void BankAccount::deposit(double amount)
{
    std::string text = "Deposit: +" + std::to_string(amount);
    transactionHistory.push_back(text);
}

bool BankAccount::withdraw(double amount)
{
    if (balance < amount)
    {
        return false;
    }
    else
    {
        std::string text = "Withdrawal: -" + std::to_string(amount);
        transactionHistory.push_back(text);
        return true;
    }
}

void BankAccount::printHistory() const
{
    for (const auto &s : transactionHistory)
    {
        std::cout << s;
    }
}

void BankAccount::displayInfo() const
{
    std::cout << owner << " " << iban << " " << balance << std::endl;
    printHistory();
}

bool BankAccount::operator==(const BankAccount &other) const
{
    return iban == other.iban;
}

std::ostream &operator<<(std::ostream &os, const BankAccount &b)
{
    os << b.owner << " " << b.iban << " " << b.balance << "\n";
    return os;
}
