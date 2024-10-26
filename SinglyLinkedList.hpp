#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include "ILinkedList.hpp"
#include <stdexcept>

template <typename T>
struct SLL_Node
{
    T data;
    SLL_Node *next;
    SLL_Node(const T &value) : data(value), next(nullptr) {} // Constrcutor for struct
};

template <typename T>
class SinglyLinkedList : public ILinkedList<T>
{
private:
    void copy(const SinglyLinkedList &other);

public:
    SLL_Node<T> *head;

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
    SinglyLinkedList() : head(nullptr) {}
    ~SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList &other);                // Copy Constructor
    SinglyLinkedList(SinglyLinkedList &&other) noexcept;            // Move Constructor
    SinglyLinkedList &operator=(const SinglyLinkedList &other);     // Copy assign constructor
    SinglyLinkedList &operator=(SinglyLinkedList &&other) noexcept; // Move assign constructor
};

#include "SinglyLinkedList.cpp"

#endif