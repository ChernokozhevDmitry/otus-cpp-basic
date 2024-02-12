#include "gtest/gtest.h"
#include "../src/mydoublylinkedlist.hpp"
#include "aux-for-list.h"

const int BEGIN = 0, SIZE = 10;

void add_data_to_back(MyDoublyLinkedList<int>& lst) {
    for(int i = BEGIN; i < SIZE; ++i) {
        if (i % 2 == 0) {
            lst.push_back(i);
        } else {
            lst.push_back(std::move(i));
        }     
    }
}

void add_data_to_front(MyDoublyLinkedList<int>& lst) {
    for(int i = BEGIN; i < SIZE; ++i) {
        if (i % 2 == 0) {
            lst.push_front(i);
        } else {
            lst.push_front(std::move(i));
        }     
    }
}

TEST(list_gtest, ctor_default) {
	MyDoublyLinkedList<int> lst1;
	EXPECT_EQ(0, lst1.size());
}

TEST(list_gtest, push_back) {
    MyDoublyLinkedList<int> lst;
    EXPECT_EQ(0, lst.size());
    
    lst.push_back(7);
    EXPECT_EQ(1, lst.size());
    
    lst.push_back(77);
    EXPECT_EQ(2, lst.size());

    int i = 3;
    lst.push_back(i);
    EXPECT_EQ(3, lst.size());

    add_data_to_back(lst);

    EXPECT_EQ(SIZE + 3, lst.size());
}

TEST(list_gtest, push_front) {
    MyDoublyLinkedList<int> lst;
    EXPECT_EQ(0, lst.size());
    
    lst.push_front(7);
    EXPECT_EQ(1, lst.size());
    
    lst.push_front(77);
    EXPECT_EQ(2, lst.size());

    int i = 3;
    lst.push_front(i);
    EXPECT_EQ(3, lst.size());

    add_data_to_front(lst);

    EXPECT_EQ(SIZE + 3, lst.size());
}

TEST(list_gtest, test_ctor) {
    MyDoublyLinkedList<int> lst1(10), lst2(100), lst3(1000);
    EXPECT_EQ(10, lst1.size());
    EXPECT_EQ(100, lst2.size());
    EXPECT_EQ(1000, lst3.size());
}

TEST(list_gtest, pop_back) {
    MyDoublyLinkedList<int> lst;
    lst.push_back(7);
    lst.push_back(77);

    lst.pop_back();
    EXPECT_EQ(1, lst.size());

    int i = 3;
    lst.push_back(i);
    lst.pop_back();
    EXPECT_EQ(1, lst.size());

    lst.pop_back();
    EXPECT_EQ(0, lst.size());

    add_data_to_back(lst);

    for (int i = BEGIN; i < SIZE; ++i) {
        EXPECT_EQ(SIZE - i, lst.size());
        lst.pop_back();
    }
}

TEST(list_gtest, pop_front) {
    MyDoublyLinkedList<int> lst;
    lst.push_front(7);
    lst.push_front(77);

    lst.pop_front();
    EXPECT_EQ(1, lst.size());

    int i = 3;
    lst.push_front(i);
    lst.pop_front();
    EXPECT_EQ(1, lst.size());

    lst.pop_front();
    EXPECT_EQ(0, lst.size());

    add_data_to_front(lst);

    for (int i = BEGIN; i < SIZE; ++i) {
        EXPECT_EQ(SIZE - i, lst.size());
        lst.pop_front();
    }
}

TEST(list_gtest, iterator) {
    MyDoublyLinkedList<int> lst;

    add_data_to_front(lst);

    auto it = lst.begin();

    EXPECT_EQ(SIZE - 1, *it);

    int i = 0;
    for (it = lst.begin(); it != lst.end(); ++it) {
        EXPECT_EQ(SIZE - i - 1, *it);
        i++;
    }
}

TEST(list_gtest, r_iterator) {
    MyDoublyLinkedList<int> lst;

    add_data_to_front(lst);

    auto it = lst.rbegin();

    EXPECT_EQ(BEGIN, *it);

    int i = 0;
    for (it = lst.rbegin(); it != lst.rend(); ++it) {
        EXPECT_EQ(i, *it);
        i++;
    }
}

TEST(list_gtest, erase) {
    MyDoublyLinkedList<int> lst;

    lst.push_front(7);
    lst.push_front(77);
    lst.push_front(777);

    lst.erase(2);
    EXPECT_EQ(2, lst.size());

    auto it = lst.begin();
    EXPECT_EQ(777, *it);
    ++it;
    EXPECT_EQ(7, *it);
}

TEST(list_gtest, insert) {
    MyDoublyLinkedList<int> lst;

    lst.push_back(5);
    lst.push_back(55);
    lst.push_back(555);

    lst.insert(2, 7);
    EXPECT_EQ(4, lst.size());

    auto it = lst.begin();
    EXPECT_EQ(5, *it);
    ++it;
    EXPECT_EQ(55, *it);
    ++it;
    EXPECT_EQ(7, *it);
    ++it;
    EXPECT_EQ(555, *it);
}

TEST(list_gtest, size) {
    MyDoublyLinkedList<int> lst(5);
    EXPECT_EQ(5, lst.size());
    
    lst.push_back(1);
    EXPECT_EQ(6, lst.size());
    
    lst.push_back(2);
    EXPECT_EQ(7, lst.size());

    int i = 3;
    lst.push_back(i);
    EXPECT_EQ(8, lst.size());
    
    lst.pop_back();
    EXPECT_EQ(7, lst.size());

    lst.erase(2);
    EXPECT_EQ(6, lst.size());
    
    lst.insert(2, 777);
    EXPECT_EQ(7, lst.size());

    MyDoublyLinkedList<int> lst1(333);
    EXPECT_EQ(333, lst1.size());
}

TEST(list_gtest, copy_ctor) {
    MyDoublyLinkedList<int> lst;

    add_data_to_front(lst);

    MyDoublyLinkedList<int> copylst(lst);

    auto it = copylst.rbegin();
    int i = 0;
    for (it = copylst.rbegin(); it != copylst.rend(); ++it) {
        EXPECT_EQ(i, *it);
        i++;
    }
}

TEST(list_gtest, move_ctor) {
    MyDoublyLinkedList<int> lst;

    add_data_to_front(lst);

    MyDoublyLinkedList<int> movelst(std::move(lst));

    EXPECT_EQ(0, lst.size());
    EXPECT_EQ(SIZE, movelst.size());

    auto it = movelst.rbegin();
    int i = 0;
    for (it = movelst.rbegin(); it != movelst.rend(); ++it) {
        EXPECT_EQ(i, *it);
        i++;
    }
}

TEST(list_gtest, assignment_operator) {
    MyDoublyLinkedList<int> lst;

    add_data_to_front(lst);

    MyDoublyLinkedList<int> copylst = lst;

    auto it = lst.begin();
    for (auto copy_it = copylst.begin(); copy_it != copylst.end(); ++copy_it) {
        EXPECT_EQ(*it, *copy_it);
        ++it;
    }
}

TEST(list_gtest, dtor) {
    {
        LstElemCounter val1;
        MyDoublyLinkedList<LstElemCounter> lst1;
        lst1.push_back(val1);
        lst1.push_back(std::move(val1));
        lst1.push_back(val1);
        lst1.push_back(std::move(val1));
        lst1.push_back(val1);
        lst1.push_back(std::move(val1));

        lst1.insert(2, val1);
        lst1.insert(2, val1);
        lst1.insert(2, val1);

        lst1.push_front(val1);
        lst1.push_front(std::move(val1));
        lst1.push_front(val1);
        lst1.push_front(std::move(val1));
        lst1.push_front(val1);
        lst1.push_front(std::move(val1));

        MyDoublyLinkedList<LstElemCounter> lst2(3); 
        MyDoublyLinkedList<LstElemCounter> lst3(lst2);
        MyDoublyLinkedList<LstElemCounter> lst4 = lst3;
        MyDoublyLinkedList<LstElemCounter> lst5(std::move(lst4));
    }
    EXPECT_EQ(0, LstElemCounter::m_counter);
}