#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value): data(value), right(nullptr), left(nullptr) {}
};

int minDepth(Node* root){
    if(root == nullptr){
        return 0;
    }
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    return min(leftDepth, rightDepth) +1;
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

int main()
{
    Node *root = nullptr;

\
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    cout << "minimum depth: " << minDepth(root) << endl;
 

    return 0;
}