#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include "ILinkedList.hpp"
#include <stdexcept>

template <typename T>
struct DLL_Node
{
    T data;
    DLL_Node *prev;
    DLL_Node *next;
    DLL_Node(const T &value) : data(value), prev(nullptr), next(nullptr) {} // Constrcutor
};

template <typename T>
class DoublyLinkedList : public ILinkedList<T>
{
private:
    void copy(const DoublyLinkedList &other);

public:
    DLL_Node<T> *head;
    DLL_Node<T> *tail;

    void insertAtHead(const T &value) override;
    void deleteAtHead() override;

    void insertAtTail(const T &value) override;
    void deleteAtTail() override;

    void insertAt(int index, const T &value) override;
    void deleteAt(int index) override;

    T &operator[](int index) override;
    const T &operator[](int index) const override;

    int findFirst(const T &value) const override;
    int findLast(const T &value) const override;

    // Rule of 5
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList &other);                // Copy Constructor
    DoublyLinkedList(DoublyLinkedList &&other) noexcept;            // Move Constructor
    DoublyLinkedList &operator=(const DoublyLinkedList &other);     // Copy Assign Constructor
    DoublyLinkedList &operator=(DoublyLinkedList &&other) noexcept; // Move assign Constructor
};

#include "DoublyLinkedList.cpp"

#endif