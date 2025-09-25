#include "../src/LinkedList.h"
#include "test_utils.h"
#include <iostream>
#include <cassert>


int main() {
    auto list = LinkedList<int>();

    // Test push_front
    list.push_front(1);
    assert(list.count() == 1);
    assert(list.get(0) == 1);
    testPastMsg("push_front");
    std::cout << list << " " << list.count() << "elements\n" << std::endl;

    // Test push_back
    list.push_back(2);
    assert(list.count() == 2);
    assert(list.get(1) == 2);
    testPastMsg("push_back");
    std::cout << list << " " << list.count() << "elements\n" << std::endl;

    // Test operator[]
    // Note: operator[] has a bug (does not check bounds, wrong index logic), so this may crash
    // Uncomment if fixed
    assert(list[0] == 1);
    assert(list[1] == 2);
    testPastMsg("operator[]");
    std::cout << list << " " << list.count() << "elements\n" << std::endl;

    // Test insert (insert after first element)
    list.insert(1, 3); // Insert 3 at index 1
    assert(list.count() == 3);
    testPastMsg("insert");
    std::cout << list << " " << list.count() << "elements\n" << std::endl;

    // Test pop_back
    list.pop_back();
    assert(list.count() == 2);
    testPastMsg("pop_back");
    std::cout << list << " " << list.count() << "elements\n" << std::endl;

    // Test pop_front
    list.pop_front();
    assert(list.count() == 1);
    testPastMsg("pop_front");
    std::cout << list << " " << list.count() << "elements\n" << std::endl;


    // Test remove
    list.push_back(2);
    list.push_back(3);
    std::cout << list << " " << list.count() << "elements\n" << std::endl;
    list.remove(1);
    assert(list.count() == 2);
    testPastMsg("remove");
    std::cout << list << " " << list.count() << "elements\n" << std::endl;

    // Test clear
    list.push_back(10);
    list.push_back(20);
    list.clear();
    assert(list.count() == 0);
    testPastMsg("clear");
    std::cout << list << " " << list.count() << "elements\n" << std::endl;

    // Test get out-of-range
    try {
        list.get(0);
        assert(false); // Should not reach here
    }
    catch (const std::out_of_range&) {
        // Expected
    }

    std::cout << "All tests passed!" << std::endl;
    return 0;
}