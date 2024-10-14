#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool isCircular()
    {
        if (!head)
            return false;
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
            if (temp == head)
            {
                return true;
            }
            return false;
        }
    }
};

int main() {
    LinkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    
    if (ll.isCircular()) {
        cout << "The list is circular." << endl;
    } else {
        cout << "The list is not circular." << endl;
    }
    
    return 0;
}