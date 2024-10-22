#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
void inorder(Node *root)
{

    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
}

Node *findMin(Node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return new Node(key);
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

void InsertAnElement(Node *&root, int key)
{
    root = insert(root, key);
}

bool isBSTUtil(Node* node, int min, int max){
    if(node==nullptr){
        return true;
    }
    if(node->data>max || node->data<min){
        return false;
    }
    return isBSTUtil(node->left, min, node->data-1) && isBSTUtil(node->right, node->data + 1, max);
}


bool isBST(Node* node){
    return isBSTUtil(node, INT_MIN, INT_MAX);
}

int main()
{
    Node *root = nullptr;
    InsertAnElement(root, 20);
    InsertAnElement(root, 10);
    InsertAnElement(root, 30);
    InsertAnElement(root, 5);
    InsertAnElement(root, 15);

    if (isBST(root)) {
        cout << "The tree is a BST." << endl;
    } else {
        cout << "The tree is not a BST." << endl;
    }

    inorder(root);

    return 0;
}