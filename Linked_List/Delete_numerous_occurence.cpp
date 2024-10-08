#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    Node* next;

    Node(int value): data(value), next(nullptr) {}
};

class SinglyLinkedList {
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
        while(temp->next != nullptr){
            temp = temp-> next;
        }
        temp->next = newNode;
    }

    int countOccurence(int key){
        int count = 0;
        Node* temp = head;
        while(temp != nullptr){
            if(temp -> data == key){
                count++;
            }
            temp = temp->next;
        }
        return count;
    }

    void deleteOccurences(int key){
        while(head != nullptr && head->data == key){
            Node* temp = head;
            head = head->next;
            delete temp;l
        }
        Node* current = head;
        while(current!=nullptr & current->next != nullptr){
            if(current -> next -> data == key){
                Node* temp = current -> next;
                current -> next = current -> next -> next;
                delete temp;

            }
            else{
                current  = current-> next;
            }
        }
    }

    void displayList(){
        Node* temp = head;
        while(temp!=nullptr){
            cout << temp-> data << endl;
            temp  = temp->next;

        }
        cout << "null\n";
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(1);

    int key = 1;
    int count = list.countOccurence(key);
    cout << "Occurrences of " << key << ": " << count << endl;

    list.deleteOccurences(key);

    cout << "List after deleting occurrences of " << key << ": ";
    list.displayList();

    return 0;
}