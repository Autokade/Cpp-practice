#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* findCommonNodes(Node* LL1, Node* LL2){
    Node* p1 = LL1;
    Node* p2 = LL2;
    Node* head3 = nullptr;
    Node* tail3 = nullptr;

    while(p1 != nullptr && p2 != nullptr){
        if(p1->data == p2->data){
            if(head3 == nullptr){
                head3 = p1;
                tail3 = p1;

            }
            else{
                tail3->next = p1;
                tail3 = tail3->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }else if(p1->data < p2->data){
            p1 = p1->next;
        }
        else{
            p2 = p2->next;
        }
    }
if(tail3 != nullptr){
    tail3->next = nullptr;
}
return head3;


}