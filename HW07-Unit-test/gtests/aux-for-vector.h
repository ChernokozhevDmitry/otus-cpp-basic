#pragma once

// класс-счетчик
// class ElemCounter  {
// public:
//     ElemCounter(int& m_counter) : m_counter(++m_counter) {}
//     ~ElemCounter() {--m_counter;}
//     int& m_counter;
// };

// класс-счетчик vector
class VecElemCounter  {
public:
    VecElemCounter() { 
        ++m_counter;
        std::cout << "          vec ctor" << m_counter << std::endl;
    }
    ~VecElemCounter() {
        --m_counter;
        std::cout << "vec dtor" << m_counter << std::endl;
    }
    static int m_counter;
};

int VecElemCounter::m_counter = 0;