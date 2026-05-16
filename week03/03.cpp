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

    void copyFrom(const LinkedList &other)
    {
        if (!other.head)
        {
            head = nullptr;
            return;
        }
        head = new Node(other.head->data);
        Node *currentThis = head;
        Node *currentOther = other.head->next;

        while (currentOther)
        {
            currentThis->next = new Node(currentOther->data);
            currentThis = currentThis->next;
            currentOther = currentOther->next;
        }
    }

    void free()
    {
        Node *current = head;
        while (current)
        {
            Node *toDelete = current;
            current = current->next;
            delete toDelete;
        }
        head = nullptr;
    }

public:
    LinkedList() : head(nullptr) {}

    LinkedList(const LinkedList &other)
    {
        copyFrom(other);
    }

    LinkedList &operator=(const LinkedList &other)
    {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }

    ~LinkedList()
    {
        free();
    }

    void pushFront(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void pushBack(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            return;
        }

        Node *current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void print() const
    {
        Node *current = head;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
    }
};

int main()
{
    LinkedList list;
    list.pushFront(3);
    list.pushFront(2);
    list.pushBack(4);
    list.pushBack(5);

    list.print();
    std::cout << std::endl;

    LinkedList copy = list;
    copy.print();
}