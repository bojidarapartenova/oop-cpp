#include <cstddef>
class MovieCD
{
private:
    char *title;
    double rentalPrice;
    int availableCopies;

    void copyTitle(const char *source)
    {
        if (!source)
        {
            title = nullptr;
            return;
        }

        int len = 0;
        while (source[len] != '\0')
        {
            len++;
        }

        title = new char[len + 1];
        for (size_t i = 0; i < len; i++)
        {
            title[i] = source[i];
        }
        title[len] = '\0';
    }

public:
    MovieCD() = default;
    MovieCD(const char *title, double rentalPrice, int availableCopies);
    MovieCD(const MovieCD &other);
    MovieCD &operator=(const MovieCD &other);
    MovieCD(MovieCD &&other) noexcept;
    MovieCD &operator=(MovieCD &&other) noexcept;
    ~MovieCD();

    double getTotalRentalValue() const;
    bool isAvailable() const;
    void print() const;
};