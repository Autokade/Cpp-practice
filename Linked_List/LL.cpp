#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1){
        data = data1;
        next = nullptr;
    }

};

Node* convertarr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp; 
    }
    return head;
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertarr2LL(arr);
    cout << head->data;
    Node *curr = head;
    while(curr!=nullptr){
        cout<<curr<<" data: "<<curr->data<<" next: "<< curr->next<<endl;
        curr = curr->next;
    }
}

