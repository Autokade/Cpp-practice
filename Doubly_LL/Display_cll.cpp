#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList{
    Node* head;

    public:
    CircularLinkedList(){
        head = nullptr;
    }
    
    void insertAtEnd(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = newNode;
            head -> next = head;

        }
        else{
            Node* temp = head;
            while(temp -> next != head){
                temp = temp -> next;
            }
            temp -> next = newNode;
            newNode -> next = head;
        }

    }

    void Display(){
        if(!head){
            return;
        }
        Node* temp = head;
        do{
            cout << temp -> data << endl;
            temp = temp -> next;
        }
        while(temp != head);
            cout << head -> data << endl;
    }

};

int main() {
    CircularLinkedList cll;
    int elements[] = {20, 100, 40, 80, 60};
    for (int element : elements) {
        cll.insertAtEnd(element);
    }
    cll.Display();
    return 0;
}