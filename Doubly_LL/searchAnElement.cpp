#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

};


bool search(int value){
    Node* head;
    Node* current  = head;
    while(current){
        if(current -> data == value){
            return true;

        }
        current = current -> next;
    }
    return false;
}