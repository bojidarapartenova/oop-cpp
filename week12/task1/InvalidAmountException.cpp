#include "InvalidAmountException.h"

InvalidAmountException::InvalidAmountException(double amount) : BankException("Invalid amount: $" + std::to_string(amount) + ". Amount must be positive"), invalidAmount(amount) {}
