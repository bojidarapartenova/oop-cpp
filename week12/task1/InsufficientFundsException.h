#ifndef INSUFFICIENTFUNDSEXCEPTION_H
#define INSUFFICIENTFUNDSEXCEPTION_H

#include "BankException.h"

class InsufficientFundsException : public BankException
{
private:
    double requested;
    double available;

public:
    InsufficientFundsException(double requested, double available);
};

#endif