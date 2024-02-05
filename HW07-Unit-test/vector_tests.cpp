// #include <vector>

#include "vector_tests.h"

namespace VectorTests{
    int BEGIN = 0, SIZE = 1000;

    void add_data_to_vector(MyVector<int>& vec) {
        for(int i = BEGIN; i < SIZE; ++i) {
            if (i % 2 == 0) {
                vec.push_back(i);
            } else {
                vec.push_back(std::move(i));
            }     
        }

    }

    bool test_ctor_default() {
        MyVector<int> vec1, vec2, vec3;
        if (vec1.size() != 0 && vec1.capacity() != 0 &&
            vec2.size() != 0 && vec2.capacity() != 0 &&
            vec3.size() != 0 && vec3.capacity() != 0) { return false;}  

        return true;
    }

    bool test_push_back() {
        MyVector<int> vec;
        if (vec.size() != 0) { return false;}  
        
        vec.push_back(1);
        if (vec.size() != 1) { return false;}  
        
        vec.push_back(2);
        if (vec.size() != 2) { return false;}  

        int val = 3;
        vec.push_back(val);
        if (vec.size() != 3) { return false;}  

        add_data_to_vector(vec);

        if (vec.size() != 1003) { return false;}  

        return true;
    }

    bool test_ctor() {
        MyVector<int> vec1(10), vec2(100), vec3(1000);
        if (vec1.size() != 100 &&
            vec2.size() != 100 &&
            vec3.size() != 1000) { return false;}  

        return true;
    }

    bool test_pop_back() {
        MyVector<int> vec;
        vec.push_back(1);
        vec.push_back(2);

        vec.pop_back();
        if (vec.size() != 1) { return false;}  

        int val = 3;
        vec.push_back(val);
        vec.pop_back();
        if (vec.size() != 1) { return false;}  

        vec.pop_back();
        if (vec.size() != 0) { return false;}  

        add_data_to_vector(vec);

        for (int i = BEGIN; i < SIZE; ++i) {
            if ( vec.size() != SIZE - i) { return false;}
            vec.pop_back();
        }

        return true;
    }

    bool test_access_by_index() {
        MyVector<int> vec;

        add_data_to_vector(vec);

        for (int i = BEGIN; i < SIZE; ++i) {
            if ( vec[i] != i ) { return false;}
        }
        
        return true;
    }

    bool test_iterator() {
        MyVector<int> vec;

        add_data_to_vector(vec);

        auto it = vec.begin();
        if ( *it != BEGIN ) { return false;}

        int i = 0;
        for (it = vec.begin(); it != vec.end(); ++it) {
            if ( *it != i ) { return false;}
            i++;
        }
        return true;
    }    

    bool test_erase_front() {
        MyVector<int> vec;

        add_data_to_vector(vec);

        for(int i = 0; i < 10; ++i) {
            if ((vec.size() != SIZE - i) || (vec[0] != i)) { return false;}
            vec.erase(0);
        }

        return true;
    }

    bool test_erase_back() {
        MyVector<int> vec;

        add_data_to_vector(vec);

        for(int i = 1; i <= 10; ++i) {
            vec.erase(SIZE - i);
            if ((vec.size() != SIZE - i) || (vec[SIZE - i] != SIZE - i)) { return false;}
        }

        return true;
    }

    bool test_erase_middle() {
        MyVector<int> vec;

        add_data_to_vector(vec);

        for(int i = 1; i <= 10; ++i) {
            vec.erase(500);
            if ((vec.size() != SIZE - i) || (vec[500] != 500 + i)) { return false;}
        }

        return true;
    }

    bool test_insert_front() {
        MyVector<int> vec;

        vec.push_back(5);

        vec.insert(0, 7);
        if ((vec.size() != 2) || (vec[0] != 7)) { return false;}

        vec.insert(0, 77);
        if ((vec.size() != 3) || (vec[0] != 77)) { return false;}

        vec.insert(0, 777);
        if ((vec.size() != 4) || (vec[0] != 777)) { return false;}


        return true;
    }

    bool test_insert_middle() {
        MyVector<int> vec;

        vec.push_back(5);
        vec.push_back(55);
        vec.push_back(555);

        vec.insert(1, 7);
        if ((vec.size() != 4) || (vec[1] != 7)) { return false;}

        vec.insert(2, 77);
        if ((vec.size() != 5) || (vec[2] != 77)) { return false;}

        vec.insert(3, 777);
        if ((vec.size() != 6) || (vec[3] != 777)) { return false;}


        return true;
    }

    bool test_size(const int size) {
        MyVector<int> vec;
        if (vec.size() != 0) { return false;}  
        
        vec.push_back(1);
        if (vec.size() != 1) { return false;}  
        
        vec.push_back(2);
        if (vec.size() != 2) { return false;}  

        int val = 3;
        vec.push_back(val);
        if (vec.size() != 3) { return false;}  
        
        vec.pop_back();
        if (vec.size() != 2) { return false;}  

        vec.erase(0);
        if (vec.size() != 1) { return false;}  
        
        vec.insert(0, 1);
        if (vec.size() != 2) { return false;}  

        MyVector<int> vec1(size);
          if (vec1.size() != size) { return false;}  
        
        return true;
    }

    bool test_copy_ctor() {
        MyVector<int> vec;

        add_data_to_vector(vec);

        MyVector<int> copyvec(vec);

        for(int i = BEGIN; i < SIZE; ++i) {
            if (vec[i] != copyvec[i]) { return false;}
        }


        return true;
    }

    bool test_move_ctor() {
        MyVector<int> vec;

        add_data_to_vector(vec);

        MyVector<int> movevec(std::move(vec));

        if ((vec.size() != 0) || (movevec.size() != SIZE)) { return false;}

        for(int i = BEGIN; i < SIZE; ++i) {
            if (movevec[i] != i) { return false;}
        }


        return true;
    }

    bool test_assignment_operator() {
        MyVector<int> vec;

        add_data_to_vector(vec);

        MyVector<int> copyvec = vec;

        for(int i = BEGIN; i < SIZE; ++i) {
            if (vec[i] != copyvec[i]) { return false;}
        }


        return true;
    }
}

