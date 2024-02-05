#include <iostream>
#include <cassert>

#include "vector_tests.h"
// #include "singlylinckedlist_tests.h"
// #include "doublylinckedlist_tests.h"

int main() {
    std::cout << "vector_tests \t test_ctor_default \t" << std::flush;
    assert(VectorTests::test_ctor_default());
    std::cout << "OK" << std::endl;

    std::cout << "vector_tests \t test_push_back \t" << std::flush;
    assert(VectorTests::test_push_back());
    std::cout << "OK" << std::endl;

    std::cout << "vector_tests \t test_ctor \t" << std::flush;
    assert(VectorTests::test_ctor());
    std::cout << "OK" << std::endl;

    std::cout << "vector_tests \t test_pop_back \t" << std::flush;
    assert(VectorTests::test_pop_back());
    std::cout << "OK" << std::endl;

    std::cout << "vector_tests \t test_access_by_index \t" << std::flush;
    assert(VectorTests::test_access_by_index());
    std::cout << "OK" << std::endl;

    std::cout << "vector_tests \t test_iterator \t" << std::flush;
    assert(VectorTests::test_iterator());
    std::cout << "OK" << std::endl;

    std::cout << "vector_tests \t test_erase_front \t" << std::flush;
    assert(VectorTests::test_erase_front());
    std::cout << "OK" << std::endl;

    std::cout << "vector_tests \t test_erase_back \t" << std::flush;
    assert(VectorTests::test_erase_back());
    std::cout << "OK" << std::endl;

    std::cout << "vector_tests \t test_erase_middle \t" << std::flush;
    assert(VectorTests::test_erase_middle());
    std::cout << "OK" << std::endl;

    std::cout << "vector_tests \t test_insert_front \t" << std::flush;
    assert(VectorTests::test_insert_front());
    std::cout << "OK" << std::endl;

    std::cout << "vector_tests \t test_insert_middle \t" << std::flush;
    assert(VectorTests::test_insert_middle());
    std::cout << "OK" << std::endl;

    std::cout << "vector_tests \t test_size \t" << std::flush;
    assert(VectorTests::test_size(333));
    std::cout << "OK" << std::endl;

    std::cout << "vector_tests \t test_copy_ctor \t" << std::flush;
    assert(VectorTests::test_copy_ctor());
    std::cout << "OK" << std::endl;

    std::cout << "vector_tests \t test_move_ctor \t" << std::flush;
    assert(VectorTests::test_move_ctor());
    std::cout << "OK" << std::endl;

    std::cout << "vector_tests \t test_assignment_operator \t" << std::flush;
    assert(VectorTests::test_assignment_operator());
    std::cout << "OK" << std::endl;

    MyVector<int> vec(100);
    
    return 0;
}