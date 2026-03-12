#include <iostream>
#include <string>
#include "02.h"

bool ValidationUtils::isEmpty(const std::string &value)
{
    return value.size() == 0;
}

bool ValidationUtils::isNumber(const std::string &value)
{
    if (value.size() == 0)
    {
        return false;
    }

    for (char c : value)
    {
        if (!(c >= '0' && c <= '9'))
        {
            return false;
        }
    }
    return true;
}

bool ValidationUtils::isValidEmail(const std::string &email)
{
    int atIndex = -1;
    int atCount = 0;

    int dotIndex = -1;

    for (size_t i = 0; i < email.size(); i++)
    {
        if (email[i] == '@')
        {
            atIndex = i;
            atCount++;
        }

        if (email[i] == '.')
        {
            dotIndex = i;
        }

        if (atCount > 1)
        {
            return false;
        }
    }

    if (atIndex <= 0)
    {
        return false;
    }

    if (dotIndex <= atIndex + 1)
    {
        return false;
    }

    if (dotIndex >= email.size() - 1)
    {
        return false;
    }
    return true;
}

bool ValidationUtils::isValidLength(const std::string &value, size_t min, size_t max)
{
    return (value.size() >= min && value.size() <= max);
}

bool ValidationUtils::isAlphabetic(const std::string &value)
{
    for (char c : value)
    {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
        {
            return false;
        }
    }
    return true;
}

bool ValidationUtils::isAlphanumeric(const std::string &value)
{
    for (char c : value)
    {
        if (!((c >= '0' && c <= '9') || ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))))
        {
            return false;
        }
    }
    return true;
}

bool ValidationUtils::isInRange(int value, int min, int max)
{
    return (value >= min && value <= max);
}

bool ValidationUtils::isValidFacultyNumber(const std::string &fn)
{
    if (fn.size() != 10)
    {
        return false;
    }

    if (!(fn[0] >= '0' && fn[0] <= '9'))
    {
        return false;
    }

    for (size_t i = 1; i <= 2; i++)
    {
        if (!(fn[i] >= 'A' && fn[i] <= 'Z'))
        {
            return false;
        }
    }

    for (size_t i = 3; i <= 9; i++)
    {
        if (!(fn[i] >= '0' && fn[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}

bool ValidationUtils::startsWith(const std::string &value, const std::string &prefix)
{
    if (prefix.size() > value.size())
    {
        return false;
    }

    for (size_t i = 0; i < prefix.size(); i++)
    {
        if (value[i] != prefix[i])
        {
            return false;
        }
    }
    return true;
}

bool ValidationUtils::endsWith(const std::string &value, const std::string &suffix)
{
    if (suffix.size() > value.size())
    {
        return false;
    }

    for (size_t i = 0; i < suffix.size(); i++)
    {
        if (value[value.size() - 1 - i] != suffix[suffix.size() - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string value;
    std::cin >> value;
    std::cout << ValidationUtils::isValidFacultyNumber(value);
}