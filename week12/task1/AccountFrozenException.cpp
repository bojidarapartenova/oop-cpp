#include "AccountFrozenException.h"

AccountFrozenException::AccountFrozenException(const std::string &accountNumber) : BankException("Account $" + accountNumber + " is frozen"), accountNumber(accountNumber) {}
