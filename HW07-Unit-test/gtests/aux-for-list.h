#pragma once

#include<iostream>
// класс-счетчик
// class ElemCounter  {
// public:
//     ElemCounter(int& m_counter) : m_counter(++m_counter) {}
//     ~ElemCounter() {--m_counter;}
//     int& m_counter;
// };

// класс-счетчик list
class LstElemCounter  {
public:
    LstElemCounter() { 
        ++m_counter;
        std::cout << "          lst ctor" << m_counter << std::endl;
    }
    ~LstElemCounter() {
        --m_counter;
        std::cout << "lst dtor" << m_counter << std::endl;
    }
    static int m_counter;
};

int LstElemCounter::m_counter = 0;