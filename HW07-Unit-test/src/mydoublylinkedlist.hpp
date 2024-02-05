#pragma once
#include <iostream>

//  doubly linked list
template<class T>
class MyDoublyLinkedList {
private:
    class Node {
    public:
        Node() : m_next(nullptr), m_prev(nullptr)  {}
        Node(const T& value) : m_value(value), m_next(nullptr), m_prev(nullptr) {}
        T m_value;
        Node* m_next;
        Node* m_prev;
    };
public:
    class Iterator {
    public:
        Iterator() noexcept : m_node(nullptr) {}
        Iterator(Node* node) noexcept : m_node(node) {}
        void operator++() {
            m_node = m_node->m_next;
        }

        void operator--() {
            m_node = m_node->m_prev;
        }
        bool operator!=(const Iterator& iterator) {
            return m_node != iterator.m_node;
        }

        T& operator*() {
            return m_node->m_value;
        }

        T& get() {
            return m_node->m_value;
        }

        private:
            Node* m_node;
    };
public:
    MyDoublyLinkedList();
    explicit MyDoublyLinkedList(int size); // конструктор с заданным количеством
    MyDoublyLinkedList(const MyDoublyLinkedList& rhs); // конструктор копирования  
    MyDoublyLinkedList(MyDoublyLinkedList&& moved) noexcept; // конструктор перемещения  
    ~MyDoublyLinkedList();

    bool empty() const;
    int size() const;
    void push_back(const T& value);
    void push_back(T&& value);
    void push_front(const T& value);
    void push_front(T&& value);
    void erase(int index);
    void pop_back();
    void pop_front();
    void insert(int index, const T& value);
    void print_list() const;
    void print_addr() const;

    Iterator begin() const {
        return Iterator(m_head);
    }
    Iterator end() const {
        return Iterator(nullptr);
    }

    Iterator rbegin() const {
        return Iterator(m_last);
    }
    Iterator rend() const {
        return Iterator(nullptr);
    }

    

private:
   int m_size;
   Node* m_head;
   Node* m_last;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const MyDoublyLinkedList<T>& value);

#include "mydoublylinkedlist.inl"
