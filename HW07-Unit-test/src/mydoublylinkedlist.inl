#include "mydoublylinkedlist.hpp"

//  singly linked list

template <class T>
MyDoublyLinkedList<T>::MyDoublyLinkedList() : m_size(0), m_head(nullptr), m_last(nullptr) {}

template <class T>
MyDoublyLinkedList<T>::MyDoublyLinkedList(int size) : MyDoublyLinkedList<T>::MyDoublyLinkedList() {
    for (int i = 0; i < size; ++i) {
        if (empty()) {
            Node* temp = new Node();
            m_head = temp;
            m_last = temp;
        } else {
            Node* temp = new Node();
            m_last->m_next = temp;
            temp->m_prev = m_last;
            m_last = temp;
        } 
        ++m_size;
    }
}

template <class T>
MyDoublyLinkedList<T>::MyDoublyLinkedList(const MyDoublyLinkedList& rhs) :
                                          MyDoublyLinkedList<T>::MyDoublyLinkedList{rhs.m_size}{
    m_head->m_value = rhs.m_head->m_value;
    m_last = m_head->m_next;
    for(Node* temp = rhs.m_head->m_next; temp != nullptr; temp = temp->m_next) {
        m_last->m_value = temp->m_value;
        m_last = m_last->m_next;
    }
}

template <class T>
MyDoublyLinkedList<T>::MyDoublyLinkedList(MyDoublyLinkedList&& moved) noexcept {
    m_size = moved.m_size;
    moved.m_size = 0;
    m_head = moved.m_head;
    moved.m_head = nullptr;
    m_last = moved.m_last;
    moved.m_last = nullptr;
}

template <class T>
MyDoublyLinkedList<T>::~MyDoublyLinkedList() {
    while (m_head) {
        Node* temphead = m_head->m_next;
        delete m_head;
        m_head = temphead;
    }
}

template <class T>
bool MyDoublyLinkedList<T>::empty() const {
    return m_head == nullptr;
}

template <class T>
int MyDoublyLinkedList<T>::size() const {
    return m_size;
}

template <class T>
void MyDoublyLinkedList<T>::push_back(const T& value) {
    Node* temp = new Node(value);
    if (empty()) {
        m_head = temp;
        m_last = temp;
    } else {
        m_last->m_next = temp;
        temp->m_prev = m_last;
        m_last = temp;
    }
    ++m_size;
}

template <class T>
void MyDoublyLinkedList<T>::push_back(T&& value) {
    Node* temp = new Node(value);
    if (empty()) {
        m_head = std::move(temp);
        m_last = std::move(temp);
    } else {
        m_last->m_next = std::move(temp);
        temp->m_prev = std::move(m_last);
        m_last = std::move(temp);
    }
    ++m_size;
}

template <class T>
void MyDoublyLinkedList<T>::push_front(const T& value) {
    Node* temp = new Node(value);
    if (empty()) {
        m_head = temp;
        m_last = temp;
    } else {
        temp->m_next = m_head;
        m_head->m_prev = temp;
        m_head = temp;
    }
    ++m_size;
}

template <class T>
void MyDoublyLinkedList<T>::push_front(T&& value) {
    Node* temp = new Node(value);
    if (empty()) {
        m_head = std::move(temp);
        m_last = std::move(temp);
    } else {
        temp->m_next = std::move(m_head);
        m_head->m_prev = std::move(temp);
        m_head = std::move(temp);
    }
    ++m_size;
}

template <class T>
void MyDoublyLinkedList<T>::erase(const int index) {
    if (!empty()) {
        Node* temp = m_head;
        int i = 1;
        while (i < index) {
            temp = temp->m_next;
            ++i;
        }
        Node* left = temp->m_prev;
        Node* right = temp->m_next;
        left->m_next = right;
        right->m_prev = left;
        delete temp;
    }
    --m_size;
}

template <class T>
void MyDoublyLinkedList<T>::pop_back() {
    if (!empty()) {
        Node* temp = m_last->m_prev;
        temp->m_next = nullptr;
        delete m_last;
        m_last = temp;
    }
    --m_size;
}

template <class T>
void MyDoublyLinkedList<T>::pop_front() {
    Node* temp = m_head;
    m_head = temp->m_next;
    delete temp;
    --m_size;
}

template <class T>
void MyDoublyLinkedList<T>::insert(const int index, const T& value) {
    Node* left = m_head;
    int i = 1;
    while (i < index) {
        left = left->m_next;
        ++i;
    }
    Node* right = left->m_next;

    Node* temp = new Node(value);
    temp->m_next = right;
    temp->m_prev = left;
    left->m_next = temp;
    right->m_prev = temp;
    ++m_size;
}

template <class T>
void MyDoublyLinkedList<T>::print_list() const {
    Node* temp = m_head;
    std::cout << temp.m_value << " ";
    while (temp) {
        std::cout << temp.m_value << " ";
        temp = temp.m_next;
    }
    std::cout << '\n';
}

template <class T>
void MyDoublyLinkedList<T>::print_addr() const {
    Node* temp = m_head;
    std::cout << temp << " ";
    while (temp) {
        std::cout << temp->m_next << " ";
        temp = temp->m_next;
    }
    std::cout << '\n';
}


template <class T>
std::ostream &operator<<(std::ostream &os, const MyDoublyLinkedList<T> &value) {
    for (const auto& v : value) {
        std::cout << v << ' ';
    }
    return os;
}