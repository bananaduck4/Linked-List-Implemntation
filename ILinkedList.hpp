#ifndef I_LINKED_LIST_HPP
#define I_LINKED_LIST_HPP

template <typename T>
class ILinkedList
{
public:
    virtual void insertAtHead(const T &value) = 0;
    virtual void deleteAtHead() = 0;

    virtual void insertAtTail(const T &value) = 0;
    virtual void deleteAtTail() = 0;

    virtual void insertAt(int index, const T &value) = 0;
    virtual void deleteAt(int index) = 0;

    virtual T &operator[](int index) = 0;
    virtual const T &operator[](int index) const = 0;

    virtual int findFirst(const T &value) const = 0;
    virtual int findLast(const T &value) const = 0;
};

#endif