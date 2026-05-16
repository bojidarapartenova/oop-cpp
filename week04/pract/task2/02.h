
#include <string>

class ValidationUtils
{
public:
    ValidationUtils() = delete;

    static bool isEmpty(const std::string &value);
    static bool isNumber(const std::string &value);
    static bool isValidEmail(const std::string &email);
    static bool isValidLength(const std::string &value, size_t min, size_t max);
    static bool isAlphabetic(const std::string &value);
    static bool isAlphanumeric(const std::string &value);
    static bool isInRange(int value, int min, int max);
    static bool isValidFacultyNumber(const std::string &fn);
    static bool startsWith(const std::string &value, const std::string &prefix);
    static bool endsWith(const std::string &value, const std::string &suffix);
};