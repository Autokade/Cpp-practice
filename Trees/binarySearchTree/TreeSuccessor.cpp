#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* parent;

};

Node* TreeMinimum(Node* x){
    while(x->left != nullptr){
        x = x->left;
    }
    return x;
}


Node* treeSuccessor(Node* x){
    if(x->right != nullptr){
        return TreeMinimum(x->right);
    }

    Node* y = x->parent;
    while(y!=nullptr && x == y->right){
        x = y;
        y = y->parent;
    }
    return x;
}