#include <cstddef>
class BigNumber
{
private:
    char *digits;
    size_t size;

    void copyNum(const BigNumber &other)
    {
        size = other.size;
        digits = new char[size];
        for (size_t i = 0; i < size; i++)
        {
            digits[i] = other.digits[i];
        }
    }

public:
    BigNumber();
    BigNumber(const BigNumber &other);
    BigNumber &operator=(const BigNumber &other);
    BigNumber(BigNumber &&other) noexcept;
    BigNumber &operator=(BigNumber &&other) noexcept;
    ~BigNumber();

    size_t length() const;
    bool isZero() const;
    void removeLeadingZeros();
};