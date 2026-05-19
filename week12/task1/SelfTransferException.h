#ifndef SELFTRANSFEREXCEPTION_H
#define SELFTRANSFEREXCEPTION_H

#include "BankException.h"

class SelfTransferException : public BankException
{
public:
    SelfTransferException();
};

#endif