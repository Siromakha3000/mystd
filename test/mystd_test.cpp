#include <iostream>
#include <ostream>

#include "../src/Array.h"



int main() {
    auto array = Array<int>(20);
    for (int i = 0; i < 20; i++)
    {
        array[i] = 20 - i;
    }
    std::cout << "creation: " << array << std::endl;
    array.resize(10);
    std::cout << "resized: " << array << std::endl;
    array.map([](const int& element, size_t i)
    {
        return element + 10;
    });
    std::cout << "mapped: " << array << std::endl;
    array.filter([](const int& element, size_t i)
    {
        return element % 2 == 0;
    });
    std::cout << "filtered: " << array << std::endl;
    array.sort();
    std::cout << "sorted: " << array << std::endl;
}
