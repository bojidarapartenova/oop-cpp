#include "01.h"
#include <iostream>

Matrix::Matrix(size_t r, size_t c) : rows(r), cols(c)
{
    data = new double *[rows];
    for (size_t i = 0; i < rows; i++)
    {
        data[i] = new double[cols]{0.0};
    }
}

Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols)
{
    data = new double *[rows];
    for (size_t i = 0; i < rows; i++)
    {
        data[i] = new double[cols];
        for (size_t j = 0; j < cols; j++)
        {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this == &other)
    {
        return *this;
    }

    for (size_t i = 0; i < rows; i++)
    {
        delete[] data[i];
    }
    delete[] data;

    rows = other.rows;
    cols = other.cols;

    data = new double *[rows];
    for (size_t i = 0; i < rows; i++)
    {
        data[i] = new double[cols];
        for (size_t j = 0; j < cols; j++)
        {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}

Matrix::~Matrix()
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] data[i];
    }

    delete[] data;
}

double &Matrix::at(size_t r, size_t c)
{
    return data[r][c];
}

const double &Matrix::at(size_t r, size_t c) const
{
    return data[r][c];
}

Matrix Matrix::transposed() const
{
    Matrix result(cols, rows);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}

size_t Matrix::getRows() const
{
    return this->rows;
}

size_t Matrix::getCols() const
{
    return this->cols;
}

int main()
{
}