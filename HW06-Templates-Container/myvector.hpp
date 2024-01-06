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
    explicit MyVector(const int num); // конструктор с заданным количеством
    MyVector(const MyVector& rhs); // конструктор копирования  
    MyVector(MyVector&& moved) noexcept; // конструктор перемещения  
    ~MyVector();
    void print_elem() const;
    void print_addr() const;
    void push_back(T&& value);
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

    friend std::ostream& operator<<(std::ostream& os, const MyVector<T>& value) {
        for (const auto& v : value) {
            std::cout << v << ' ';
        }    
        return os;
    }

private:
    Iterator end_capacity() const {
        return Iterator(&m_elem[m_capacity]);
    }
    void setcapacity(const T&& value); 
    int m_size;       // количество элементов вектора
    int m_capacity;  // емкость вектора
    T* m_elem;            // элементы вектора
    const double mem_reserve_coeff = 2; // коэффициент резервирования памяти 
};

// MyVector
template <class T>
MyVector<T>::MyVector() : m_size(0), m_capacity(0), m_elem{nullptr}{}

template <class T>
MyVector<T>::MyVector(const int size) : MyVector<T>::MyVector{} {
    if (size > 0) {
        m_size = size;
        m_capacity = size;
        m_elem = new T[size];
    }
}

template <class T>
MyVector<T>::MyVector(const MyVector& rhs) : MyVector<T>::MyVector{rhs.m_size} {
    for (int i = 0; i < rhs.m_size; ++i) {
        m_elem[i] = rhs.m_elem[i];
    }
    std::cout << "Copy Ctor\n";
}

template <class T>
MyVector<T>::MyVector(MyVector&& moved) noexcept
{
    m_elem = moved.m_elem;
    moved.m_elem = nullptr;
    m_size = moved.m_size;
    moved.m_size = 0;
    m_capacity = moved.m_capacity;
    moved.m_capacity = 0;
    std::cout << "Move Ctor\n";
}

template <class T>
MyVector<T>::~MyVector() {
    delete[] m_elem;
    std::cout << "Dtor\n";
}    

template <class T>
void MyVector<T>::print_elem() const {
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_elem[i] << " ";
    }
    std::cout  << " | ";
    for (int i = m_size; i < m_capacity; ++i) {
        std::cout << m_elem[i] << " ";
    }
    std::cout  << "\n";
}

template <class T>
void MyVector<T>::print_addr() const {
    for (int i = 0; i < m_size; ++i) {
        std::cout << &m_elem[i] << " ";
    }
    std::cout  << " | ";
    for (int i = m_size; i < m_capacity; ++i) {
        std::cout << &m_elem[i] << " ";
    }
    std::cout  << "\n";
}

template <class T>
void MyVector<T>::push_back(T&& value) {    
    if (m_size == 0) {
        m_elem = new T(std::move(value));
    }
    else if (m_size >= m_capacity) {
        setcapacity(std::move(value));
    } 
    else {
        m_elem[m_size] = std::move(value);
    }
    ++m_size;
}


template <class T>
void MyVector<T>::pop_back() {
    if (m_size > 0) {
        --m_size;
    }
    else {
        std::cout << "vector is empty.\n"; 
    }
    
}

template <class T>
void MyVector<T>::erase(int index) {
    if ((index >= 0) && (index < m_size)) {
        for(int i = index; i < m_size-1; ++i) {
            m_elem[i] = m_elem[i+1];
        }
        --m_size;
    }
    else {
        std::cout << "index incorrect.\n"; 
    }
}

template <class T>
void MyVector<T>::insert(int index, const T&& value) {
    if ((index >= 0) && (index < m_size)) {
        if (m_size == 0) {
            m_elem = new T(std::move(value));
        }
        else if (m_size >= m_capacity) {
            setcapacity(std::move(value));
        } 
        for(int i = m_size-1 ; i >= index; --i){
            m_elem[i+1]=std::move(m_elem[i]);
        }
        m_elem[index] = std::move(value);
        ++m_size;
    }
    else {
        std::cout << "index incorrect.\n"; 
    }    
}

template <class T>
int MyVector<T>::size() const {
    return m_size;
}

template <class T>
int MyVector<T>::capacity() const {
    return m_capacity;
}

template <class T>
bool MyVector<T>::empty() const {
    return m_size == 0;
}

template <class T>
T& MyVector<T>::operator[](int i) {
    return m_elem[i];
}

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector& rhs) {
    if (rhs.m_size > m_size) {
        delete[] m_elem;
        m_elem = new T[rhs.m_size];
    }
    for (int i = 0; i < rhs.m_size; ++i) {
        m_elem[i] = rhs.m_elem[i];
    }
    m_size = rhs.m_size;
    return *this;
}

template <class T>
void MyVector<T>::setcapacity(const T&& value) {
    // static_cast<int>(m_capacity *= mem_reserve_coeff); // как тут преобразовать, чтобы не было warning C4244: *=: преобразование "const double" в "int", возможна потеря данных              
    m_capacity = static_cast<int>(m_size * mem_reserve_coeff);
    if (m_size >= m_capacity) {
        m_capacity += m_size;
    }
    T* temp = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        temp[i] = std::move(m_elem[i]);
    }
    temp[m_size] = std::move(value);
    delete[] m_elem;
    m_elem = temp;

}