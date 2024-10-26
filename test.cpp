// DoublyLinkedList.hpp

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "ILinkedList.hpp"
#include <stdexcept>

template <typename T>
struct DLL_Node
{
    T data;
    DLL_Node *prev;
    DLL_Node *next;
    DLL_Node(const T &value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList : public ILinkedList<T>
{
public:
    DLL_Node<T> *head;
    DLL_Node<T> *tail;

    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor
    ~DoublyLinkedList()
    {
        while (head)
        {
            deleteAtHead();
        }
    }

    // Copy Constructor
    DoublyLinkedList(const DoublyLinkedList &other) : head(nullptr), tail(nullptr)
    {
        DLL_Node<T> *temp = other.head;
        while (temp)
        {
            insertAtTail(temp->data);
            temp = temp->next;
        }
    }

    // Move Constructor
    DoublyLinkedList(DoublyLinkedList &&other) noexcept : head(other.head), tail(other.tail)
    {
        other.head = nullptr;
        other.tail = nullptr;
    }

    // Copy Assignment Operator
    DoublyLinkedList &operator=(const DoublyLinkedList &other)
    {
        if (this != &other)
        {
            while (head)
            {
                deleteAtHead();
            }
            head = tail = nullptr;
            DLL_Node<T> *temp = other.head;
            while (temp)
            {
                insertAtTail(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }

    // Move Assignment Operator
    DoublyLinkedList &operator=(DoublyLinkedList &&other) noexcept
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

    // Function Overrides
    void insertAtHead(const T &value) override
    {
        DLL_Node<T> *newNode = new DLL_Node<T>(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void deleteAtHead() override
    {
        if (!head)
            return;
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

    void insertAtTail(const T &value) override
    {
        DLL_Node<T> *newNode = new DLL_Node<T>(value);
        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtTail() override
    {
        if (!tail)
            return;
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

    void insertAt(int index, const T &value) override
    {
        if (index < 0)
            throw std::out_of_range("Index out of range");
        if (index == 0)
        {
            insertAtHead(value);
            return;
        }
        DLL_Node<T> *temp = head;
        for (int i = 0; i < index - 1; ++i)
        {
            if (!temp)
                throw std::out_of_range("Index out of range");
            temp = temp->next;
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

    void deleteAt(int index) override
    {
        if (index < 0 || !head)
            throw std::out_of_range("Index out of range");
        if (index == 0)
        {
            deleteAtHead();
            return;
        }
        DLL_Node<T> *temp = head;
        for (int i = 0; i < index; ++i)
        {
            if (!temp)
                throw std::out_of_range("Index out of range");
            temp = temp->next;
        }
        if (!temp)
            throw std::out_of_range("Index out of range");
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

    T &operator[](int index) override
    {
        if (index < 0)
            throw std::out_of_range("Index out of range");
        DLL_Node<T> *temp = head;
        for (int i = 0; i < index; ++i)
        {
            if (!temp)
                throw std::out_of_range("Index out of range");
            temp = temp->next;
        }
        if (!temp)
            throw std::out_of_range("Index out of range");
        return temp->data;
    }

    const T &operator[](int index) const override
    {
        if (index < 0)
            throw std::out_of_range("Index out of range");
        DLL_Node<T> *temp = head;
        for (int i = 0; i < index; ++i)
        {
            if (!temp)
                throw std::out_of_range("Index out of range");
            temp = temp->next;
        }
        if (!temp)
            throw std::out_of_range("Index out of range");
        return temp->data;
    }

    int findFirst(const T &value) const override
    {
        DLL_Node<T> *temp = head;
        int index = 0;
        while (temp)
        {
            if (temp->data == value)
                return index;
            temp = temp->next;
            ++index;
        }
        return -1;
    }

    int findLast(const T &value) const override
    {
        DLL_Node<T> *temp = tail;
        int index = 0;
        while (temp)
        {
            if (temp->data == value)
                return index;
            temp = temp->prev;
            --index;
        }
        return -1;
    }
};

#endif // DOUBLYLINKEDLIST_HPP
