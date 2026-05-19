#include "BankException.h"

BankException::BankException(const std::string &message) : message(message) {}

const char *BankException::what() const noexcept
{
    return message.c_str();
}
