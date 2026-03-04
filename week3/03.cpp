#include <iostream>
#include <string>

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;

        Node() : data(0), next(nullptr) {};
        Node(int data) : data(data), next(nullptr) {};
    };

private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    LinkedList(const LinkedList &linkedList) : head(linkedList.head) {}

    ~LinkedList()
    {
        delete[] head;
    }

    void pushFront(int data)
    {
    }
};

int main()
{
}