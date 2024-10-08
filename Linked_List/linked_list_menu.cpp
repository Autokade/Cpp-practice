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

int main() {
    SinglyLinkedList list;
    int choice, value, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific node\n";
        cout << "8. Search for a node\n";
        cout << "9. Display all nodes\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertatBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertatEnd(value);
                break;
            case 3:
                int afterValue;
                cout << "Enter the value of the node after which to insert: ";
                cin >> afterValue;
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAfter(afterValue, value);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Enter value of the node to delete: ";
                cin >> value;
                list.deleteSpecificNode(value);
                break;
            case 8:
                cout << "Enter value to search for: ";
                cin >> value;
                pos = list.searchNode(value);
                if (pos != -1) {
                    cout << "Node found at position: " << pos << endl;
                } else {
                    cout << "Node not found\n";
                }
                break;
            case 9:
                list.displayList();
                break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 10);

    return 0;
}