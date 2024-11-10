#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value): data(value), left(nullptr), right(nullptr){}


};
void inorder(Node* root){

    if(root != nullptr){
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);

    }
}


Node* insert(Node* root, int key){
    if(root == nullptr){
        return new Node(key);
    }

    if(key < root->data){
        root->left = insert(root->left, key);
    }
    else if(key > root->data){
        root->right = insert(root->right, key);
    }
    return root;
}


void InsertAnElement(Node*& root, int key){
    root = insert(root, key);
}


int main() {
    Node* root = nullptr;
    InsertAnElement(root, 20);
    InsertAnElement(root, 10);
    InsertAnElement(root, 30);
    InsertAnElement(root, 5);
    InsertAnElement(root, 15);
    inorder(root);

    
    return 0;
}