#include "gtest/gtest.h"
#include "../src/myvector.hpp"

class ElemCounter  {
public:
    ElemCounter() {}
    ElemCounter(int* counter) : counter{counter} {}
    ~ElemCounter() {
        if (counter) {
            ++(*counter);
        }
    }
    int* counter;
};

TEST(vector_gtest, dtor_4capacity_3elem) {
    int counter{};
    {
        MyVector<ElemCounter> vec;
        vec.push_back(ElemCounter(&counter));
        vec.push_back(ElemCounter(&counter));
        vec.push_back(ElemCounter(&counter));

        counter = 0;
    }
    EXPECT_EQ(3, counter);
}

TEST(vector_gtest, dtor_4capacity_4elem) {
    int counter{};
    {
        MyVector<ElemCounter> vec;
        vec.push_back(ElemCounter(&counter));
        vec.push_back(ElemCounter(&counter));
        vec.push_back(ElemCounter(&counter));
        vec.push_back(ElemCounter(&counter));

        counter = 0;
    }
    EXPECT_EQ(4, counter);
}