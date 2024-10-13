#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void displayBackward() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
    void deleteNode(int value){
        if(head == nullptr){
            return;
        }
        Node* temp = head;

        while(temp != nullptr && temp->data != value){
            temp = temp-> next;
        } 

        if(temp != nullptr){
            if(temp == head){
                head = temp->next;
                if (head != nullptr)
                {
                    head -> prev = nullptr;
                }
                else if(temp == tail){
                    tail = temp ->prev;
                    tail -> next = nullptr;
                }
                else{
                    temp->prev->next = temp->next;
                }
                
            }
            delete temp;
        }
        else{
            cout << "Node with value not found" << endl;
        }

    }

    bool search(int value){
        Node* current = head;
        while(current != nullptr ){
            if(current -> data = value ){
                return true;
            }
            current = current -> next;
        }
        return false;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    cout << "List in forward direction: ";
    list.displayForward();

    cout << "List in backward direction: ";
    list.displayBackward();

    return 0;
}
