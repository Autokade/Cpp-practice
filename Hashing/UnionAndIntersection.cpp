#include <iostream>
#include<unordered_set>
using namespace std;


struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


void insert(Node*& head, int val){
    Node* newNode = new Node(val);

    newNode ->next = head;

    head = newNode;
}

void printList(Node* head){
    Node* curr = head;
    while(curr){
        cout << curr->data << " ";
        curr = curr->next;

    }
    cout << endl;
}

Node* getUnion(Node* head1,Node* head2){
    unordered_set<int> seen;

    Node* unionList = nullptr;
    Node* curr = head1;
    while(curr){
        if(seen.find(curr->data) == seen.end()){
            seen.insert(curr->data);
            insert(unionList, curr->data);
        }
        curr = curr -> next;
    }
    return unionList;
}

Node* getIntersection(Node* head1, Node* head2){
    unordered_set<int> set1;
    Node* intersectionList = nullptr;

    Node* curr = head1;
    while(curr){
        set1.insert(curr->data);
        curr = curr->next;
    }

    unordered_set<int> seen;

    curr = head2;

    while(curr){
        if(set1.find(curr->data) != set1.end() && 
        seen.find(curr->data) == seen.end()){
            insert(intersectionList, curr->data);
            seen.insert(curr->data);
        }
        curr = curr->next;
    }
    return intersectionList;
}

int main(){

    Node* list1 = nullptr;
    Node* list2 = nullptr;

    insert(list1, 5);
    insert(list1, 4);
    insert(list1, 3);
    insert(list1, 2);
    insert(list1, 1);

    insert(list1, 8);
    insert(list1, 7);
    insert(list1, 6);
    insert(list1, 5);
    insert(list1, 4);

    cout <<"First List: ";
    printList(list1);

    cout << "Second List: ";
    printList(list2);

    Node* unionList = getUnion(list1,list2);
    cout << "Union List: ";
    printList(unionList);

    Node* intersectionList = getIntersection(list1, list2);
    cout << "Intersection List: ";
    printList(intersectionList);

    return 0;
}