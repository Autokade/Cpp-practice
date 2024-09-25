#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};


int main(){
    Node* head = nullptr;
    Node* temp = new Node;

    int num;
    cin >> num;

    temp ->data = num;
    temp ->next = nullptr; 

    head = temp;

    cout << "Node data: " << head -> data << endl;

    return 0;


}