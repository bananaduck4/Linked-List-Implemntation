#ifndef DOUBLY_LINKED_LIST_CPP
#define DOUBLY_LINKED_LIST_CPP

#include "DoublyLinkedList.hpp"

// Destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (head)
    {
        deleteAtHead();
    }
}

template <typename T>
void DoublyLinkedList<T>::copy(const DoublyLinkedList &other)
{
    DLL_Node<T> *temp = other.head;
    while (temp)
    {
        insertAtTail(temp->data);
        temp = temp->next;
    }
}

// Copy Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList &other) : head(nullptr), tail(nullptr)
{
    copy(other);
}

// Copy Assignment Operator
template <typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(const DoublyLinkedList &other)
{
    if (this != &other)
    {
        while (head)
        {
            deleteAtHead();
        }
        head = tail = nullptr;
        copy(other);
    }

    return *this;
}

// Move Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList &&other) noexcept : head(other.head), tail(other.tail)
{
    other.head = nullptr;
    other.tail = nullptr;
}

// Move Assignment Operator
template <typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(DoublyLinkedList &&other) noexcept
{
    if (this != &other)
    {
        while (head)
        {
            deleteAtHead();
        }

        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
    }

    return *this;
}

template <typename T>
void DoublyLinkedList<T>::insertAtHead(const T &value)
{
    DLL_Node<T> *newHead = new DLL_Node<T>(value);
    if (!head)
    {
        head = tail = newHead;
        return;
    }

    newHead->next = head;
    head->prev = newHead;
    head = newHead;
}

template <typename T>
void DoublyLinkedList<T>::deleteAtHead()
{
    if (!head)
    {
        return;
    }

    DLL_Node<T> *temp = head;
    if (head == tail)
    {
        head = tail = nullptr;
    }

    else
    {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
}

template <typename T>
void DoublyLinkedList<T>::insertAtTail(const T &value)
{
    DLL_Node<T> *newNode = new DLL_Node<T>(value);
    if (!tail)
    {
        head = tail = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

template <typename T>
void DoublyLinkedList<T>::deleteAtTail()
{
    if (!tail)
    {
        return;
    }

    DLL_Node<T> *temp = tail;
    if (head == tail)
    {
        head = tail = nullptr;
    }

    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete temp;
}

template <typename T>
void DoublyLinkedList<T>::insertAt(int index, const T &value)
{
    if (index < 0 || !head || !tail)
    {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0)
    {
        insertAtHead(value);
        return;
    }

    DLL_Node<T> *temp = head;
    for (int i = 0; i < index - 1; ++i)
    {
        temp = temp->next;
        if (!temp)
        {
            throw std::out_of_range("Index out of range");
        }
    }
    DLL_Node<T> *newNode = new DLL_Node<T>(value);
    newNode->next = temp->next;
    if (temp->next)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
    newNode->prev = temp;

    if (!newNode->next)
    {
        tail = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::deleteAt(int index)
{
    if (index < 0 || !head || !tail)
    {
        throw std::out_of_range("Index out of range");
    }

    if (index == 0)
    {
        deleteAtHead();
        return;
    }

    DLL_Node<T> *temp = head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
        if (!temp)
        {
            throw std::out_of_range("Index out of range");
        }
    }

    if (temp->prev)
    {
        temp->prev->next = temp->next;
    }

    if (temp->next)
    {
        temp->next->prev = temp->prev;
    }

    if (temp == tail)
    {
        tail = temp->prev;
    }

    delete temp;
}

template <typename T>
T &DoublyLinkedList<T>::operator[](int index)
{
    if (index < 0 || !head || !tail)
    {
        throw std::out_of_range("Index out of range");
    }

    DLL_Node<T> *temp = head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
        if (!temp)
        {
            throw std::out_of_range("Index out of range");
        }
    }

    return temp->data;
}

template <typename T>
const T &DoublyLinkedList<T>::operator[](int index) const
{
    if (index < 0 || !head || !tail)
    {
        throw std::out_of_range("Index out of range");
    }

    DLL_Node<T> *temp = head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
        if (!temp)
        {
            throw std::out_of_range("Index out of range");
        }
    }

    return temp->data;
}

template <typename T>
int DoublyLinkedList<T>::findFirst(const T &value) const
{
    DLL_Node<T> *temp = head;
    int index = 0;
    while (temp)
    {
        if (temp->data == value)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }

    return -1;
}

template <typename T>
int DoublyLinkedList<T>::findLast(const T &value) const
{
    DLL_Node<T> *temp = head;
    int i = 0;
    int index = -1;
    while (temp)
    {
        if (temp->data == value)
        {
            index = i;
        }
        temp = temp->next;
        i++;
    }

    return index;
}

#endif
