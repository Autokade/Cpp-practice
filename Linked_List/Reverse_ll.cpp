#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {};
};

class SinglyLinkedList{
    Node* head;

    public:
    SinglyLinkedList() : head(nullptr) {};

    void insertAtEnd(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            return;
        }
        else{
            Node* temp = head;
            while(temp->next!=nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }

    }

    void reverseList(){
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while(current!=nullptr){
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
     void displayList(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp -> data <<endl;
            temp = temp-> next;

        }
        cout << "NULL \n" << endl;
     }
};



int main() {
    SinglyLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    cout << "Original List: ";
    list.displayList();

    list.reverseList();

    cout << "Reversed List: ";
    list.displayList();

    return 0;
}