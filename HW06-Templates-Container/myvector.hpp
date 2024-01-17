#pragma once

#include <iostream>

template <class T>
class MyVector {
public:
    class Iterator
    {
    public:
        Iterator() noexcept : itr_ptr_(nullptr) {}
        Iterator(T * itr_ptr) noexcept : itr_ptr_(itr_ptr) {}
        Iterator& operator++() {
            ++itr_ptr_;
            return *this;
        }
        bool operator!=(const Iterator& iterator) {
            return itr_ptr_ != iterator.itr_ptr_;
        }
        T& operator*() {
            return *itr_ptr_;
        }
        T& get() {
            return *itr_ptr_;
        }
    private:
        T* itr_ptr_;
    };

    MyVector();// = default;
    explicit MyVector(int size); // конструктор с заданным количеством
    MyVector(const MyVector& rhs); // конструктор копирования  
    MyVector(MyVector&& moved) noexcept; // конструктор перемещения  
    ~MyVector();
    void print_elem() const;
    void print_addr() const;
    void push_back(T&& value);
    void push_back(const T& value);
    void pop_back();
    void erase(int index);
    void insert(int index, const T&& value);
    int size() const;
    int capacity() const;
    bool empty() const;
    T& operator[](int i);
    MyVector<T>& operator=(const MyVector& rhs);

    Iterator begin() const {
        return Iterator(&m_elem[0]);
    }
    Iterator end() const {
        return Iterator(&m_elem[m_size]);
    }

private:
    void setcapacity(const T&& value); 
    void setcapacity(const T& value); 
    int m_size;       // количество элементов вектора
    int m_capacity;  // емкость вектора
    T* m_elem;            // элементы вектора
    const double mem_reserve_coeff = 2; // коэффициент резервирования памяти 
};



template <class T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& value);

#include "myvector.inl"
