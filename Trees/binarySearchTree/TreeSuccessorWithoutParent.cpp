#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}

};

Node* TreeMinimum(Node* x){
    while(x->left != nullptr){
        x = x->left;
    }
    return x;
}


Node* treeSuccessorWithoutParent(Node* root, Node* x){
    if(x->right != nullptr){
        return TreeMinimum(x->right);
    }
    Node* succ = nullptr;
    Node* y = root;

    while(y!= nullptr){
        if(x->data < y->data){
            succ = y;
            y = y->left;
        }
        else if(x->data > y->data){
            y = y->right; 
        }
        else{
            break;
        }
    }
    return succ;
    
}