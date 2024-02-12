#include "gtest/gtest.h"
#include "../src/myvector.hpp"
#include "aux-for-vector.h"

const int BEGIN = 0, SIZE = 10;

void add_data_to_vector(MyVector<int>& vec) {
    for(int i = BEGIN; i < SIZE; ++i) {
        if (i % 2 == 0) {
            vec.push_back(i);
        } else {
            vec.push_back(std::move(i));
        }     
    }
}

TEST(vector_gtest, ctor_default) {
	MyVector<int> vec1;

	EXPECT_EQ(0, vec1.size());
	EXPECT_EQ(0, vec1.capacity());
}

TEST(vector_gtest, push_back) {
    MyVector<int> vec;
    EXPECT_EQ(0, vec.size());
    
    vec.push_back(7);
    EXPECT_EQ(1, vec.size());
    
    vec.push_back(77);
    EXPECT_EQ(2, vec.size());

    int i = 3;
    vec.push_back(i);
    EXPECT_EQ(3, vec.size());

    add_data_to_vector(vec);

    EXPECT_EQ(SIZE + 3, vec.size());
}

TEST(vector_gtest, ctor) {
    MyVector<int> vec1(10), vec2(100), vec3(1000);
    EXPECT_EQ(10, vec1.size());
    EXPECT_EQ(100, vec2.size());
    EXPECT_EQ(1000, vec3.size());
}

TEST(vector_gtest, pop_back) {
    MyVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);

    vec.pop_back();
    EXPECT_EQ(1, vec.size());

    int i = 3;
    vec.push_back(i);
    vec.pop_back();
    EXPECT_EQ(1, vec.size());

    vec.pop_back();
    EXPECT_EQ(0, vec.size());

    add_data_to_vector(vec);

    for (int i = BEGIN; i < SIZE; ++i) {
        EXPECT_EQ(SIZE - i, vec.size());
        vec.pop_back();
    }
}

TEST(vector_gtest, access_by_index) {
    MyVector<int> vec;

    add_data_to_vector(vec);

    for (int i = BEGIN; i < SIZE; ++i) {
        EXPECT_EQ(i, vec[i]);
    }
}

TEST(vector_gtest, iterator) {
    MyVector<int> vec;

    add_data_to_vector(vec);

    auto it = vec.begin();

    EXPECT_EQ(BEGIN, *it);

    int i = 0;
    for (it = vec.begin(); it != vec.end(); ++it) {
        EXPECT_EQ(i, *it);
        i++;
    }
}

TEST(vector_gtest, erase_front) {
    MyVector<int> vec;

    add_data_to_vector(vec);

    for(int i = 0; i < static_cast<int>(SIZE/2); ++i) {
        EXPECT_EQ(SIZE - i, vec.size());
        EXPECT_EQ(i, vec[0]);
        vec.erase(0);
    }
}

TEST(vector_gtest, erase_back) {
    MyVector<int> vec;

    add_data_to_vector(vec);

    for(int i = 1; i < static_cast<int>(SIZE/2); ++i) {
        vec.erase(SIZE - i);
        EXPECT_EQ(SIZE - i, vec.size());
        EXPECT_EQ(SIZE - i, vec[SIZE - i]);
    }
}

TEST(vector_gtest, erase_middle) {
    MyVector<int> vec;

    add_data_to_vector(vec);

    for(int i = 1; i < static_cast<int>(SIZE/2); ++i) {
        vec.erase(static_cast<int>(SIZE/2));
        EXPECT_EQ(SIZE - i, vec.size());
        EXPECT_EQ(static_cast<int>(SIZE/2) + i, vec[static_cast<int>(SIZE/2)]);
    }
}

TEST(vector_gtest, insert_front) {
    MyVector<int> vec;

    vec.push_back(5);

    vec.insert(0, 7);
    EXPECT_EQ(2, vec.size());
    EXPECT_EQ(7, vec[0]);

    vec.insert(0, 77);
    EXPECT_EQ(3, vec.size());
    EXPECT_EQ(77, vec[0]);

    vec.insert(0, 777);
    EXPECT_EQ(4, vec.size());
    EXPECT_EQ(777, vec[0]);
}

TEST(vector_gtest, insert_middle) {
    MyVector<int> vec;

    vec.push_back(5);
    vec.push_back(55);
    vec.push_back(555);

    vec.insert(1, 7);
    EXPECT_EQ(4, vec.size());
    EXPECT_EQ(7, vec[1]);

    vec.insert(2, 77);
    EXPECT_EQ(5, vec.size());
    EXPECT_EQ(77, vec[2]);

    vec.insert(3, 777);
    EXPECT_EQ(6, vec.size());
    EXPECT_EQ(777, vec[3]);
}

TEST(vector_gtest, size) {
    MyVector<int> vec;
    EXPECT_EQ(0, vec.size());
    
    vec.push_back(1);
    EXPECT_EQ(1, vec.size());
    
    vec.push_back(2);
    EXPECT_EQ(2, vec.size());

    int i = 3;
    vec.push_back(i);
    EXPECT_EQ(3, vec.size());
    
    vec.pop_back();
    EXPECT_EQ(2, vec.size());

    vec.erase(0);
    EXPECT_EQ(1, vec.size());
    
    vec.insert(0, 1);
    EXPECT_EQ(2, vec.size());

    MyVector<int> vec1(333);
    EXPECT_EQ(333, vec1.size());
}

TEST(vector_gtest, copy_ctor) {
    MyVector<int> vec;

    add_data_to_vector(vec);

    MyVector<int> copyvec(vec);

    for(int i = BEGIN; i < SIZE; ++i) {
        EXPECT_EQ(vec[i], copyvec[i]);
    }
}

TEST(vector_gtest, move_ctor) {
    MyVector<int> vec;

    add_data_to_vector(vec);

    MyVector<int> movevec(std::move(vec));

    EXPECT_EQ(0, vec.size());
    EXPECT_EQ(SIZE, movevec.size());

    for(int i = BEGIN; i < SIZE; ++i) {
        EXPECT_EQ(i, movevec[i]);
    }
}

TEST(vector_gtest, assignment_operator) {
    MyVector<int> vec;

    add_data_to_vector(vec);

    MyVector<int> copyvec = vec;

    for(int i = BEGIN; i < SIZE; ++i) {
        EXPECT_EQ(vec[i], copyvec[i]);
    }
}

TEST(vector_gtest, dtor) {
    {
        VecElemCounter val1;
        MyVector<VecElemCounter> vec1;
        vec1.push_back(val1);
        vec1.push_back(std::move(val1));
        vec1.push_back(val1);
        vec1.push_back(std::move(val1));
        vec1.push_back(val1);
        vec1.push_back(std::move(val1));

        vec1.insert(2, std::move(val1));
        vec1.insert(2, std::move(val1));
        vec1.insert(2, std::move(val1));

        MyVector<VecElemCounter> vec2(3); 
        MyVector<VecElemCounter> vec3(vec2);
        MyVector<VecElemCounter> vec4 = vec3;
        MyVector<VecElemCounter> vec5(std::move(vec4));
    }
    EXPECT_EQ(0, VecElemCounter::m_counter);
}

