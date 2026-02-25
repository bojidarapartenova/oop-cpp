#include <iostream>
#include <string>
#include <fstream>

class BankAccount
{
private:
    std::string accountNumber;
    std::string ownerName;
    double balance;

public:
    void setAccountNumber(std::string accountNumber_)
    {
        accountNumber = accountNumber_;
    }

    void setOwnerName(std::string ownerName_)
    {
        ownerName = ownerName_;
    }

    void setBalance(double balance_)
    {
        if (balance_ < 0)
        {
            std::cout << "Invalid balance!" << std::endl;
            balance = 0;
        }
        else
        {
            balance = balance_;
        }
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
        else
        {
            std::cout << "Amount should be a positive number!" << std::endl;
        }
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            std::cout << "You do not have enough money!" << std::endl;
        }
    }

    void exportStatement(const std::string &filename)
    {
        std::ofstream file(filename);
        if (!file)
        {
            std::cout << "Cannot open file!" << std::endl;
            return;
        }

        file << "Account number: " << accountNumber << "\n";
        file << "Owner: " << ownerName << "\n";
        file << "Balance: " << balance << "\n";
        file.close();
    }
};

int main()
{
    std::cout << "Enter Account number: ";
    std::string accountNumber;
    std::cin >> accountNumber;

    std::cout << "Enter Owner name: ";
    std::string ownerName;
    std::cin.ignore();
    std::getline(std::cin, ownerName);

    std::cout << "Enter Balance: ";
    double balance;
    std::cin >> balance;

    BankAccount bankAccount;
    bankAccount.setAccountNumber(accountNumber);
    bankAccount.setOwnerName(ownerName);
    bankAccount.setBalance(balance);

    std::cout << "Choose an action (deposit/withdraw) or exit: ";
    std::string action;
    std::cin >> action;

    while (action != "exit")
    {
        if (action != "deposit" && action != "withdraw")
        {
            std::cout << "Invalid action!" << std::endl;
        }
        else
        {
            std::cout << "Enter amount: ";
            double amount;
            std::cin >> amount;

            if (action == "deposit")
            {
                bankAccount.deposit(amount);
            }
            else if (action == "withdraw")
            {
                bankAccount.withdraw(amount);
            }
        }
        std::cout << "Choose an action (deposit/withdraw) or exit: ";
        std::cin >> action;
    }
    std::cout << "Enter a file name: ";
    std::string fileName;
    std::cin >> fileName;
    bankAccount.exportStatement(fileName);
}