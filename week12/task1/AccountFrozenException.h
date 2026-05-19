#ifndef ACCOUNTFROZENEXCEPTION_H
#define ACCOUNTFROZENEXCEPTION_H

#include "BankException.h"

class AccountFrozenException : public BankException
{
private:
    std::string accountNumber;

public:
    AccountFrozenException(const std::string &accountNumber);
};

#endif