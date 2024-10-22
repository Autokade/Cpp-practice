#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

    void postOrder(Node* root, vector<int> &arr){
        if(root == nullptr){
            return;
        }

        postOrder(root->left, arr);
        postOrder(root->right, arr);
        arr.push_back(root->data);
    }

vector<int> PostOrder(Node* root){
    vector<int> arr;
    postOrder(root, arr);
    return arr;
}


int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    vector<int> result = PostOrder(root);
    cout << "PostOrder Traversal: ";
    for(int val : result){
        cout << val << "";

    }
    cout << endl;

    return 0;
}