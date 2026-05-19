#include "InsufficientFundsException.h"

InsufficientFundsException::InsufficientFundsException(double requested, double available) : BankException("Insufficient funds: requested $" + std::to_string(requested) + ", available $" + std::to_string(available)), requested(requested), available(available) {}
