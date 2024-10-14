#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList { 
    Node* head;
    public:
    CircularLinkedList(){
        head = nullptr;
    }

    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            head -> next = newNode;
        }

        else{
            Node* temp = head;
            while(temp -> next != head){
                temp  = temp -> next;
            }
            temp -> next = newNode;
            newNode -> next = head;
        }
    }

    int size(){
        if(!head){
            int count  = 0;
            Node* temp = head;
            do{
                count++;
                temp = temp->next;
            }
            while(temp!= head);
            return count;
        }
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cout << "Size of Circular Linked List: " << cll.size() << endl;
    return 0;
}