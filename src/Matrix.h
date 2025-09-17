#pragma once
#include <stdexcept>
#include <ostream>
#include <omp.h>

template<typename T, size_t ROWS, size_t COLUMNS>
class Matrix
{
    T* data;
    const size_t rows = ROWS;
    const size_t columns = COLUMNS;
public:
    Matrix()
    {
        data = new T[ROWS * COLUMNS];
    }
    ~Matrix()
    {
        delete[] data;
    }

    T& operator()(const size_t row, const size_t col)
    {
        return data[row * COLUMNS + col];
    }
    const T& operator()(const size_t row, const size_t col) const
    {
        return data[row * COLUMNS + col];
    }

    Matrix operator+(const Matrix<T, ROWS, COLUMNS>& rhs)
    {
        Matrix result;
        for (size_t i = 0; i < ROWS; i++)
        {
            for (size_t j = 0; j < COLUMNS; j++)
            {
                result(i,j) = (*this)(i, j) + (rhs(i, j));
            }
        }
        return result;
    }
};

template <typename T, size_t ROWS, size_t COLUMNS>
std::ostream& operator<<(std::ostream& os, Matrix<T, ROWS, COLUMNS>& obj)
{
    for (size_t i = 0; i < COLUMNS; i++)
    {
        os << "[";
        for (size_t j = 0; j < ROWS - 1; j++)
        {
            os << obj(i, j) << ", ";
        }
        os << obj(i, ROWS - 1) << "]" << '\n';
    }
    return os;
};
