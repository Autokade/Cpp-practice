#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};
class SinglyLinkedList{
    Node* head;

    public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtEnd(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp -> next != nullptr){
            temp  = temp -> next;
        }
        temp -> next = newNode;
    }

    int findMiddle(){
        Node* slow = head;
        Node* fast = head;
        while(fast!=nullptr && fast->next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;


        }
        if(slow!= nullptr){
            return slow->data;
        }
        return -1;
    }

    void displayList(){
        Node* temp = head;
        while(temp!= nullptr){
            cout << temp -> data << "->";
            temp = temp-> next;
        }
        cout << "NULL\n";
    }

};

int main() {
    SinglyLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    int middleValue = list.findMiddle();
    cout << "The middle element is: " << middleValue << endl;

    return 0;
}