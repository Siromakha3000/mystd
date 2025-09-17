#include "../src/Matrix.h"
#include "test_utils.h"
#include <iostream>
#include <cassert>

int main()
{
    auto matrix = Matrix<int, 3, 2>();
    matrix(0, 0) = 1;
    matrix(0, 1) = 2;
    matrix(1, 0) = 3;
    matrix(1, 1) = 4;
    matrix(2, 0) = 5;
    matrix(2, 1) = 6;
    std::cout << matrix << std::endl;
    {

        auto matrix2 = Matrix<int, 3, 2>();
        matrix2(0, 0) = 1;
        matrix2(0, 1) = 2;
        matrix2(1, 0) = 3;
        matrix2(1, 1) = 4;
        matrix2(2, 0) = 5;
        matrix2(2, 1) = 6;
        auto matrix3 = matrix+matrix2;
        std::cout << matrix << " + \n" << matrix2 << " = \n" << matrix3 << std::endl;
    }
    // {
    //
    //     auto matrix2 = Matrix<int, 3, 2>();
    //     matrix2(0, 0) = 1;
    //     matrix2(0, 1) = 2;
    //     matrix2(0, 2) = 3;
    //     matrix2(1, 0) = 4;
    //     matrix2(1, 1) = 5;
    //     matrix2(1, 2) = 6;
    //     auto matrix3 = matrix+matrix2;
    //     std::cout << matrix << " + " << matrix2 << " = " << matrix3 << std::endl;
    // }
}
