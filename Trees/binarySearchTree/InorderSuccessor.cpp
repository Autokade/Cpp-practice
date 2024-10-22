#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *findMin(Node *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

Node *findInOrderSuccesor(Node *root, Node *node)
{
    if (node->right != nullptr)
    {
        return findMin(node->right);
    }

    Node *successor = nullptr;
    while (root != nullptr)
    {
        if (node->data < root->data)
        {
            successor = root;
            root = root->left;
        }
        else if (node->data > root->data)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }
    return successor;
}


int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->right = new Node(40);

    Node* successor = findInOrderSuccesor(root, root->left->right); // Node with data 15
    cout << "Successor of 15: " << (successor ? successor->data : -1) << endl;

}