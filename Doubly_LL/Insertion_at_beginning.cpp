#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}

    void insertAtBeginning(int value){
        Node* head;
        Node* newNode = new Node(value);
        if(!head){
            head = newNode;
        }
        else{
            newNode-> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }
};

