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

Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }

    if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        if (root->left != nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    Node *root = nullptr;
    InsertAnElement(root, 20);
    InsertAnElement(root, 10);
    InsertAnElement(root, 30);
    InsertAnElement(root, 5);
    InsertAnElement(root, 15);
    deleteNode(root, 30);
    inorder(root);

    return 0;
}