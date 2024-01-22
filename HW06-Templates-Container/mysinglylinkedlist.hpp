#pragma once
#include <iostream>

//  singly linked list
template<class T>
class MySinglyLinkedList {
private:
    class Node {
    public:
        Node() : m_next(nullptr) {}
        Node(const T& value) : m_value(value), m_next(nullptr) {}
        T m_value;
        Node* m_next;
    };
public:
    class Iterator {
    public:
        Iterator() noexcept : m_node(nullptr) {}
        Iterator(Node* node) noexcept : m_node(node) {}
        void operator++() {
            m_node = m_node->m_next;
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
    MySinglyLinkedList();
    explicit MySinglyLinkedList(int size); // конструктор с заданным количеством
    MySinglyLinkedList(const MySinglyLinkedList& rhs); // конструктор копирования  
    MySinglyLinkedList(MySinglyLinkedList&& moved) noexcept; // конструктор перемещения  
    ~MySinglyLinkedList();

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

    

private:
   int m_size;
   Node* m_head;
   Node* m_last;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const MySinglyLinkedList<T>& value);

#include "mysinglylinkedlist.inl"
