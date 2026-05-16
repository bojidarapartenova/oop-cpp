#include <cstddef>

class Matrix
{
private:
    double **data;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t r, size_t c);
    Matrix(const Matrix &other);
    Matrix &operator=(const Matrix &other);
    ~Matrix();

    double &at(size_t r, size_t c);
    const double &at(size_t r, size_t c) const;
    Matrix transposed() const;
    size_t getRows() const;
    size_t getCols() const;
};