#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>

class BankAccount
{
protected:
    std::string owner;
    std::string iban;
    double balance;
    std::vector<std::string> transactionHistory;

public:
    BankAccount(std::string owner, std::string iban, double initialBalance);
    virtual ~BankAccount() = default;

    const std::string &getOwner() const;
    const std::string &getIban() const;
    double getBalance() const;
    const std::vector<std::string> &getHistory() const;
    void deposit(double amount);
    bool withdraw(double amount);
    void printHistory() const;
    virtual void displayInfo() const;

    bool operator==(const BankAccount &other) const;

    auto operator<=>(const BankAccount &other) const
    {
        return balance <=> other.balance;
    }

    friend std::ostream &operator<<(std::ostream &os, const BankAccount &b);
};

#endif