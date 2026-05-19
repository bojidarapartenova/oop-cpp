#ifndef INVALIDAMOUNTEXCEPTION_H
#define INVALIDAMOUNTEXCEPTION_H

#include "BankException.h"

class InvalidAmountException : public BankException
{
private:
    double invalidAmount;

public:
    InvalidAmountException(double amount);
};

#endif