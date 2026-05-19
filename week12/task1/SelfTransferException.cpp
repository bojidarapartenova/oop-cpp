#include "SelfTransferException.h"

SelfTransferException::SelfTransferException() : BankException("Cannot transfer money to the same account") {}