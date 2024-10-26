#include <iostream>
#include <stdexcept>
#include "DoublyLinkedList.hpp"

void testDefaultConstructor()
{
    DoublyLinkedList<int> list;
    std::cout << "Test Default Constructor: ";
    if (list.head == nullptr && list.tail == nullptr)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }
}

void testInsertAtHead()
{
    DoublyLinkedList<int> list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);

    std::cout << "Test InsertAtHead: ";
    if (list.head->data == 30 && list.head->next->data == 20 && list.head->next->next->data == 10 && list.tail->data == 10)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }
}

void testInsertAtTail()
{
    DoublyLinkedList<int> list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    std::cout << "Test InsertAtTail: ";
    if (list.head->data == 10 && list.head->next->data == 20 && list.head->next->next->data == 30 && list.tail->data == 30)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }
}

void testDeleteAtHead()
{
    DoublyLinkedList<int> list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    list.deleteAtHead();

    std::cout << "Test DeleteAtHead: ";
    if (list.head->data == 20 && list.head->next->data == 10 && list.head->prev == nullptr && list.tail->data == 10)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }

    list.deleteAtHead();
    list.deleteAtHead();
    list.deleteAtHead(); // Deleting from an empty list should not crash

    std::cout << "Test DeleteAtHead Empty: ";
    if (list.head == nullptr && list.tail == nullptr)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }
}

void testDeleteAtTail()
{
    DoublyLinkedList<int> list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    list.deleteAtTail();

    std::cout << "Test DeleteAtTail: ";
    if (list.tail->data == 20 && list.tail->next == nullptr && list.head->next->data == 20)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }

    list.deleteAtTail();
    list.deleteAtTail();
    list.deleteAtTail(); // Deleting from an empty list should not crash

    std::cout << "Test DeleteAtTail Empty: ";
    if (list.head == nullptr && list.tail == nullptr)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }
}

void testInsertAt()
{
    DoublyLinkedList<int> list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAt(1, 15);

    std::cout << "Test InsertAt: ";
    if (list.head->data == 10 && list.head->next->data == 15 && list.head->next->next->data == 20 && list.tail->data == 30)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }

    // Test inserting at head position
    list.insertAt(0, 5);
    std::cout << "Test InsertAt Head: ";
    if (list.head->data == 5 && list.head->next->data == 10 && list.tail->data == 30)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }

    // Test inserting at tail position
    list.insertAt(5, 35);
    std::cout << "Test InsertAt Tail: ";
    if (list.tail->data == 35 && list.tail->prev->data == 30)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }

    // Test out of range
    try
    {
        list.insertAt(100, 40);
        std::cout << "Failed (Out of Range)" << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Passed (Out of Range)" << std::endl;
    }
}

void testDeleteAt()
{
    DoublyLinkedList<int> list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.deleteAt(1);

    std::cout << "Test DeleteAt: ";
    if (list.head->data == 10 && list.head->next->data == 30 && list.tail->data == 30 && list.tail->prev->data == 10)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }

    // Test deleting at head position
    list.deleteAt(0);
    std::cout << "Test DeleteAt Head: ";
    if (list.head->data == 30 && list.head->prev == nullptr && list.tail->data == 30)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }

    // Test deleting at tail position
    list.insertAtTail(40);
    list.insertAtTail(50);
    list.deleteAt(2);
    std::cout << "Test DeleteAt Tail: ";
    if (list.tail->data == 40 && list.tail->next == nullptr && list.tail->prev->data == 30)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }

    // Test out of range
    try
    {
        list.deleteAt(100);
        std::cout << "Failed (Out of Range)" << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Passed (Out of Range)" << std::endl;
    }
}

void testAccessOperator()
{
    DoublyLinkedList<int> list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    std::cout << "Test AccessOperator: ";
    try
    {
        if (list[0] == 10 && list[1] == 20 && list[2] == 30)
        {
            std::cout << "Passed" << std::endl;
        }
        else
        {
            std::cout << "Failed" << std::endl;
        }
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Failed (Out of Range)" << std::endl;
    }

    // Test out of range
    try
    {
        int val = list[100];
        std::cout << "Failed (Out of Range)" << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Passed (Out of Range)" << std::endl;
    }
}

void testFindFirst()
{
    DoublyLinkedList<int> list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(20);

    std::cout << "Test FindFirst: ";
    if (list.findFirst(20) == 1)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }

    // Test value not found
    std::cout << "Test FindFirst Not Found: ";
    if (list.findFirst(40) == -1)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }
}

void testFindLast()
{
    DoublyLinkedList<int> list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(20);

    std::cout << "Test FindLast: ";
    if (list.findLast(20) == 3)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }

    // Test value not found
    std::cout << "Test FindLast Not Found: ";
    if (list.findLast(40) == -1)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }
}

int main()
{
    testDefaultConstructor();
    testInsertAtHead();
    testInsertAtTail();
    testDeleteAtHead();
    testDeleteAtTail();
    testInsertAt();
    testDeleteAt();
    testAccessOperator();
    testFindFirst();
    testFindLast();

    return 0;
}
