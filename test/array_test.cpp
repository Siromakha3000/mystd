#include "../src/Array.h"
#include "test_utils.h"
#include <iostream>
#include <cassert>

int main() {
    auto array = Array<int>(20);

    // Test creation
    for (int i = 0; i < 20; i++) {
        array[i] = 20 - i;
    }
    std::cout << "creation: " << array << std::endl;
    assert(array.size() == 20);
    testPastMsg("creation");

    // Test resize
    array.resize(10);
    std::cout << "resized: " << array << std::endl;
    assert(array.size() == 10);
    testPastMsg("resize");

    // Test map
    array.map([](const int& element, size_t i) { return element + 10; });
    std::cout << "mapped: " << array << std::endl;
    for (size_t i = 0; i < array.size(); i++) {
        assert(array[i] == (20 - i) + 10);
    }
    testPastMsg("map");

    // Test filter
    array.filter([](const int& element, size_t i) { return element % 2 == 0; });
    std::cout << "filtered: " << array << std::endl;
    for (size_t i = 0; i < array.size(); i++) {
        assert(array[i] % 2 == 0);
    }
    testPastMsg("filter");

    // // Test sort
    // array.sort();
    // std::cout << "sorted: " << array << std::endl;
    // for (size_t i = 1; i < array.size(); i++) {
    //     assert(array[i - 1] <= array[i]);
    // }
    // testPastMsg("sort");

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
