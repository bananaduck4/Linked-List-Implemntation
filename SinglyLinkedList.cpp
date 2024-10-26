#ifndef SINGLY_LINKED_LIST_CPP
#define SINGLY_LINKED_LIST_CPP

#include "SinglyLinkedList.hpp"

// Destrcutor
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    while (head)
    {
        deleteAtHead();
    }
}

template <typename T>
void SinglyLinkedList<T>::copy(const SinglyLinkedList &other)
{
    if (!other.head) // Nothing to copy
    {
        return;
    }
    head = new SLL_Node<T>(other.head->data);

    SLL_Node<T> *curr = head;
    SLL_Node<T> *other_curr = other.head->next;

    while (other_curr)
    {
        curr->next = new SLL_Node<T>(other_curr->data);
        curr = curr->next;
        other_curr = other_curr->next;
    }
}

// Copy Constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList &other)
{
    head = nullptr;
    copy(other);
}

// Copy assign operator
template <typename T>
SinglyLinkedList<T> &SinglyLinkedList<T>::operator=(const SinglyLinkedList &other)
{
    if (this != &other)
    {
        while (head)
        {
            deleteAtHead();
        }

        copy(other);
    }

    return *this;
}

// Move Constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList &&other) noexcept
{
    head = other.head;
    other.head = nullptr;
}

// Move assignment operator
template <typename T>
SinglyLinkedList<T> &SinglyLinkedList<T>::operator=(SinglyLinkedList &&other) noexcept
{
    if (this != &other)
    {
        while (head)
        {
            deleteAtHead();
        }

        head = other.head;
        other.head = nullptr;
    }

    return *this;
}

template <typename T>
void SinglyLinkedList<T>::insertAtHead(const T &value)
{
    SLL_Node<T> *new_head = new SLL_Node<T>(value);
    new_head->next = head;
    head = new_head;
}

template <typename T>
void SinglyLinkedList<T>::deleteAtHead()
{
    if (head)
    {
        SLL_Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
}

// Add to end of list
template <typename T>
void SinglyLinkedList<T>::insertAtTail(const T &value)
{
    if (!head) // Create a node at head if null
    {
        insertAtHead(value);
        return;
    }

    SLL_Node<T> *current = head;
    while (current->next) // Check if their is a tail and if yes set that to curr
    {
        current = current->next;
    }
    current->next = new SLL_Node<T>(value);
}

template <typename T>
void SinglyLinkedList<T>::deleteAtTail()
{
    if (!head) // If no head then their is no tail
        return;

    if (!head->next) // if no tail then we delet head
    {
        delete head;
        head = nullptr;
        return;
    }

    SLL_Node<T> *current = head;
    while (current->next && current->next->next) // Traverse till second to last node
    {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

template <typename T>
void SinglyLinkedList<T>::insertAt(int index, const T &value)
{
    if (index < 0 || !head) // Negative index or no list
    {
        throw std::out_of_range("Index is out of range");
    }

    SLL_Node<T> *curr = head;
    for (int i = 0; i < index - 1; i++)
    {
        curr = curr->next;
        if (!curr || !curr->next)
        {
            throw std::out_of_range("Index is out of range");
        }
    }

    SLL_Node<T> *newNode = new SLL_Node<T>(value);
    newNode->next = curr->next;
    curr->next = newNode;
}

template <typename T>
void SinglyLinkedList<T>::deleteAt(int index)
{
    if (index < 0 || !head)
    {
        throw std::out_of_range("Index is out of range");
    }

    SLL_Node<T> *curr = head;
    for (int i = 0; i < index - 1; i++)
    {
        curr = curr->next;
        if (!curr || !curr->next)
        {
            throw std::out_of_range("Index is out of range");
        }
    }

    SLL_Node<T> *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}

template <typename T>
T &SinglyLinkedList<T>::operator[](int index)
{
    if (index < 0 || !head)
    {
        throw std::out_of_range("Index is out of range");
    }

    SLL_Node<T> *curr = head;
    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
        if (!curr)
        {
            throw std::out_of_range("Index is out of range");
        }
    }

    return curr->data;
}

template <typename T>
const T &SinglyLinkedList<T>::operator[](int index) const
{
    if (index < 0 || !head)
    {
        throw std::out_of_range("Index is out of range");
    }

    SLL_Node<T> *curr = head;
    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
        if (!curr)
        {
            throw std::out_of_range("Index is out of range");
        }
    }

    return curr->data;
}

template <typename T>
int SinglyLinkedList<T>::findFirst(const T &value) const
{
    SLL_Node<T> *curr = head;
    int index = 0;

    while (curr)
    {
        if (curr->data == value)
        {
            return index;
        }

        curr = curr->next;
        index++;
    }

    return -1;
}

template <typename T>
int SinglyLinkedList<T>::findLast(const T &value) const
{
    SLL_Node<T> *curr = head;
    int i = 0;
    int index = -1;

    while (curr)
    {
        if (curr->data == value)
        {
            index = i;
        }

        curr = curr->next;
        i++;
    }

    return index;
}

#endif