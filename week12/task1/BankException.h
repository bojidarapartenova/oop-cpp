#ifndef BANKEXCEPTION_H
#define BANKEXCEPTION_H

#include <exception>
#include <string>

class BankException : public std::exception
{
private:
    std::string message;

public:
    BankException(const std::string &message);
    ~BankException() = default;

    const char *what() const noexcept override;
};

#endif