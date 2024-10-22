#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *MaximumElement(Node *root)
{
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->right = new Node(40);

    Node *max = MaximumElement(root);
    cout << "Max: " << max->data << endl;
}