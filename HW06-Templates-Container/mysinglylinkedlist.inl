#include "mysinglylinkedlist.hpp"

//  singly linked list

template <class T>
MySinglyLinkedList<T>::MySinglyLinkedList() : m_size(0), m_head(nullptr), m_last(nullptr) {}

template <class T>
MySinglyLinkedList<T>::MySinglyLinkedList(int size) : MySinglyLinkedList<T>::MySinglyLinkedList() {
    for (int i = 0; i < size; ++i) {
        if (empty()) {
            Node* temp = new Node();
            m_head = temp;
            m_last = temp;
        } else {
            Node* temp = new Node();
            m_last->m_next = temp;
            m_last = temp;
        } 
        ++m_size;
    }
}

template <class T>
MySinglyLinkedList<T>::MySinglyLinkedList(const MySinglyLinkedList& rhs) :
                                          MySinglyLinkedList<T>::MySinglyLinkedList{rhs.m_size}{
    m_head->m_value = rhs.m_head->m_value;
    m_last = m_head->m_next;
    for(Node* temp = rhs.m_head->m_next; temp != nullptr; temp = temp->m_next) {
        m_last->m_value = temp->m_value;
        m_last = m_last->m_next;
    }
}

template <class T>
MySinglyLinkedList<T>::MySinglyLinkedList(MySinglyLinkedList&& moved) noexcept {
    m_size = moved.m_size;
    moved.m_size = 0;
    m_head = moved.m_head;
    moved.m_head = nullptr;
    m_last = moved.m_last;
    moved.m_last = nullptr;
}

template <class T>
MySinglyLinkedList<T>::~MySinglyLinkedList() {
    while (m_head) {
        Node* temphead = m_head->m_next;
        delete m_head;
        m_head = temphead;
    }
}

template <class T>
bool MySinglyLinkedList<T>::empty() const {
    return m_head == nullptr;
}

template <class T>
int MySinglyLinkedList<T>::size() const {
    return m_size;
}

template <class T>
void MySinglyLinkedList<T>::push_back(const T& value) {
    Node* temp = new Node(value);
    if (empty()) {
        m_head = temp;
        m_last = temp;
    } else {
        m_last->m_next = temp;
        m_last = temp;
    }
    ++m_size;
}

template <class T>
void MySinglyLinkedList<T>::push_back(T&& value) {
    Node* temp = new Node(value);
    if (empty()) {
        m_head = std::move(temp);
        m_last = std::move(temp);
    } else {
        m_last->m_next = std::move(temp);
        m_last = std::move(temp);
    }
    ++m_size;
}

template <class T>
void MySinglyLinkedList<T>::push_front(const T& value) {
    Node* temp = new Node(value);
    if (empty()) {
        m_head = temp;
        m_last = temp;
    } else {
        temp->m_next = m_head;
        m_head = temp;
    }
    ++m_size;
}

template <class T>
void MySinglyLinkedList<T>::push_front(T&& value) {
    Node* temp = new Node(value);
    if (empty()) {
        m_head = std::move(temp);
        m_last = std::move(temp);
    } else {
        temp->m_next = std::move(m_head);
        m_head = std::move(temp);
    }
    ++m_size;
}

template <class T>
void MySinglyLinkedList<T>::erase(const int index) {
    if (!empty()) {
        Node* temp1 = m_head;
        Node* temp2 = m_head->m_next;
        int i = 1;
        while (i < index - 1) {
            temp1 = temp1->m_next;
            temp2 = temp2->m_next;
            ++i;
        }
        temp1->m_next = temp2->m_next;
        delete temp2;
    }
    --m_size;
}

template <class T>
void MySinglyLinkedList<T>::pop_back() {
    if (!empty()) {
        Node* temp = m_head;
        while (temp->m_next != m_last) {
            temp = temp->m_next;
        }    
        temp->m_next = nullptr;
        delete m_last;
        m_last = temp;
    }
    --m_size;
}

template <class T>
void MySinglyLinkedList<T>::pop_front() {
    Node* temp = m_head;
    m_head = temp->m_next;
    delete temp;
    --m_size;
}

template <class T>
void MySinglyLinkedList<T>::insert(const int index, const T& value) {
    Node* temp1 = m_head;
    Node* temp2 = m_head->m_next;
    int i = 1;
    while (i < index) {
        temp1 = temp1->m_next;
        temp2 = temp2->m_next;
        ++i;
    }
    Node* temp = new Node(value);
    temp->m_next = temp2;
    temp1->m_next = temp;
    ++m_size;
}

template <class T>
void MySinglyLinkedList<T>::print_list() const {
    Node* temp = m_head;
    std::cout << temp.m_value << " ";
    while (temp) {
        std::cout << temp.m_value << " ";
        temp = temp.m_next;
    }
    std::cout << '\n';
}

template <class T>
void MySinglyLinkedList<T>::print_addr() const {
    Node* temp = m_head;
    std::cout << temp << " ";
    while (temp) {
        std::cout << temp->m_next << " ";
        temp = temp->m_next;
    }
    std::cout << '\n';
}


template <class T>
std::ostream &operator<<(std::ostream &os, const MySinglyLinkedList<T> &value) {
    for (const auto& v : value) {
        std::cout << v << ' ';
    }
    return os;
}