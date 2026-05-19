#include "BankAccount.h"
#include "InvalidAmountException.h"
#include "SelfTransferException.h"
#include "AccountFrozenException.h"
#include "InsufficientFundsException.h"
#include <exception>
#include <iostream>

BankAccount::BankAccount(std::string accNumber, std::string owner, double initialBalance) : accountNumber(accNumber), ownerName(owner), balance(initialBalance), isFrozen(false)
{
    if (accNumber.length() != 10)
    {
        throw new std::invalid_argument("Account number must be 10 digits");
    }

    if (owner.empty())
    {
        throw new std::invalid_argument("Owner cannot be empty");
    }

    if (initialBalance < 0)
    {
        throw new InvalidAmountException(initialBalance);
    }
}

void BankAccount::deposit(double amount)
{
    if (isFrozen)
    {
        throw new AccountFrozenException(accountNumber);
    }

    if (amount <= 0)
    {
        throw new InvalidAmountException(amount);
    }

    if (amount > 1000000)
    {
        throw new std::overflow_error("Deposit exceeds maximum limit");
    }
}

void BankAccount::withdraw(double amount)
{
    if (isFrozen)
    {
        throw new AccountFrozenException(accountNumber);
    }

    if (amount <= 0)
    {
        throw new InvalidAmountException(amount);
    }

    if (amount > balance)
    {
        throw new InsufficientFundsException(amount, balance);
    }
}

void BankAccount::transfer(BankAccount &destination, double amount)
{
    if (isFrozen)
    {
        throw new AccountFrozenException(accountNumber);
    }

    if (destination.isFrozen)
    {
        throw new AccountFrozenException(destination.accountNumber);
    }

    if (destination.accountNumber == accountNumber)
    {
        throw new SelfTransferException();
    }

    if (amount <= 0)
    {
        throw new InvalidAmountException(amount);
    }

    if (amount > balance)
    {
        throw new InsufficientFundsException(amount, balance);
    }
}

void BankAccount::freeze()
{
    isFrozen = true;
}

void BankAccount::unfreeze()
{
    isFrozen = false;
}

void BankAccount::processTransaction(BankAccount &from, BankAccount &to, double amount)
{
    try
    {
        from.transfer(to, amount);
    }
    catch (const SelfTransferException &e)
    {
        std::cerr << e.what();
    }
    catch (const InsufficientFundsException &e)
    {
        std::cerr << e.what();
    }
    catch (const AccountFrozenException &e)
    {
        std::cerr << e.what();
    }
    catch (const InvalidAmountException &e)
    {
        std::cerr << e.what();
    }
    catch (const BankException &e)
    {
        std::cerr << e.what();
    }
    catch (const std::overflow_error &e)
    {
        std::cerr << "System error: " << e.what();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unknown error: " << e.what();
    }
    catch (...)
    {
        std::cerr << "Critical unknown error occurred";
    }
    std::cout << "Transaction processing completed";
}
