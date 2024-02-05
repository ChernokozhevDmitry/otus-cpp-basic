#pragma once

#include "src/myvector.hpp"


// #include "mysinglylinkedlist.hpp"
// #include "mydoublylinkedlist.hpp"

namespace VectorTests{
    void add_data_to_vector(MyVector<int>& vec);

    bool test_ctor_default();
    bool test_push_back();
    bool test_ctor();
    bool test_pop_back();
    bool test_access_by_index();
    bool test_iterator();
    bool test_erase_front();
    bool test_erase_back();
    bool test_erase_middle();
    bool test_insert_front();
    bool test_insert_middle();
    bool test_size(int size);
    bool test_copy_ctor();
    bool test_move_ctor();
    bool test_assignment_operator();
}