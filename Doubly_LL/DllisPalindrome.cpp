#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
    Node *head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
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
            newNode->prev = temp;
        }
    }

    bool isPalindrome()
    {
        if (!head)
        {
            return true;
        }
        Node *left = head;
        Node *right = head;
        while (right->next)
        {
            right = right->next;
        }
        while (left != right && right->next != left)
        {
            if (left->data != right->data)
            {
                return false;
            }
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.insertAtEnd('r');
    dll.insertAtEnd('a');
    dll.insertAtEnd('c');
    dll.insertAtEnd('e');
    dll.insertAtEnd('c');
    dll.insertAtEnd('a');
    dll.insertAtEnd('r');
    if (dll.isPalindrome())
    {
        cout << "The list is a palindrome." << endl;
    }
    else
    {
        cout << "The list is not a palindrome." << endl;
    }
    return 0;
}
