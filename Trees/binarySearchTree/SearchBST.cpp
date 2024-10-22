#include <bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};


Node* searchRecursive(Node* root, int key){
    if(root == nullptr || root->data == key){
        return root;
    }
    if(key < root->data){
        return searchRecursive(root->left, key);

    }
    return searchRecursive(root->right,key);
}

Node* searchNonRecursive(Node* root, int key){
    while(root != nullptr && root->data != key){
        if(key < root->data){
            root =  root->left;
        }
        else{
            root = root-> right;
        }

    }
    return root;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->right = new Node(40);

    Node* search = searchRecursive(root, 15);
    cout << "Found: " << (search ? search->data : -1) << endl;


}
