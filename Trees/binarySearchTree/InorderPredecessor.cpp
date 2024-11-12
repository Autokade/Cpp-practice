#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};


Node *MaximumElement(Node *root)
{
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}

Node* findInorderPredecessor(Node* node, Node *root){
    if(node->left != nullptr){
        return MaximumElement(node->left);
    }
    Node* predecessor = nullptr;
    while(root != nullptr){
        if(node->data > root->data){
            predecessor = root;
            root = root->right;
        }
        else if(node->data < root -> data){
            root = root->left;
        }
        else{
            break;
        }

    }
    return predecessor;

}


int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->right = new Node(40);



    Node* predecessor = findInorderPredecessor(root, root->left->right); // Node with data 15
    cout << "Predecessor of 15: " << (predecessor ? predecessor->data : -1) << endl;
}c