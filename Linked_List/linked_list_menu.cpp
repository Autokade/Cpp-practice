#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
    Node(int value, Node *nextNode) : data(value), next(nextNode) {}
};

class SinglyLinkedList
{
    Node *head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertatBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertatEnd(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insertAfter(int afterValue, int value)
    {
        Node *temp = head;
        while (temp != nullptr && temp->data != afterValue)
        {
            temp = temp->next;
        }
        if (temp != nullptr)
        {
            Node *newNode = new Node(value);
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            cout << "node with value" << afterValue << "not found \n";
        }
    }

    void deleteFromBeginning()
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void deleteFromEnd()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    void deleteSpecificNode(int value)
    {
        if (head == nullptr)
            return;
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != value)
        {
            temp = temp->next;
        }
        if (temp->next != nullptr)
        {
            Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
        else{
            cout << "Node with value" << value << "not found\n";
        }
    }
    int searchNode(int value){
        Node* temp = head;
        int position = 1;
        while(temp!=nullptr){
            if(temp -> data == value){
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1;
    }
    void displayList(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp-> data << "->";
            temp = temp->next;

        }
        cout << "Null\n" ;
    }
};