#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void inOrderNonRecursive(Node *root)
{
    stack<Node *> s;
    Node *current = root;
    while (current != nullptr || !s.empty())
    {
        s.push(current);
        current = current->left;
    }

    current = s.top();
    s.pop();
    cout << current->data << " ";
    current = current->right;
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);
    cout << "In-order Traversal: ";
    inOrderNonRecursive(root);
    cout << endl;
    return 0;
}