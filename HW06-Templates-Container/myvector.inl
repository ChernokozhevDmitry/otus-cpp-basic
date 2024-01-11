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
}

template <class T>
MyVector<T>::~MyVector() {
    std::cout << "Dtor\n";
    std::cout << "m_size: " << m_size << "  " << "m_capacity: " << m_capacity << "\n";
    delete[] m_elem;

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
        // new (m_elem) T(std::move(value));
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
void MyVector<T>::push_back(const T& value) {
    if (m_size == 0) {
        m_elem = new T(value);
    }
    else if (m_size >= m_capacity) {
        setcapacity(value);
    } 
    else {
        m_elem[m_size] = value;
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
std::ostream& operator<<(std::ostream& os, const MyVector<T>& value) {
    for (const auto& v : value) {
        std::cout << v << ' ';
    }
    return os;
}

template <class T>
void MyVector<T>::setcapacity(const T&& value) {
    m_capacity = static_cast<int>(static_cast<double>(m_size) * mem_reserve_coeff);
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

template <class T>
void MyVector<T>::setcapacity(const T& value) {
    m_capacity = static_cast<int>(static_cast<double>(m_size) * mem_reserve_coeff);
    if (m_size >= m_capacity) {
        m_capacity += m_size;
    }
    T* temp = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        temp[i] = m_elem[i];
    }
    temp[m_size] = value;
    delete[] m_elem;
    m_elem = temp;

}

// T* begin() {
//           return arr;
//         }
    
// T* end() {
//     return arr + size;
// }
