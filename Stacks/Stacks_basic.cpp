#include <bits/stdc++.h>
#define MAXLEN 100
using namespace std;

struct Stack
{
    int element[MAXLEN];
    int top;
};

Stack init()
{
    Stack S;
    S.top = -1;
    return S;
}

bool isEmpty(Stack S)
{
    return (S.top == -1);
}

bool isFull(Stack S)
{
    return (S.top == MAXLEN - 1);
}

int topElement(Stack S)
{
    if (isEmpty(S))
    {
        cout << "EmptyStack/n";
        return -1;
    }
    else
    {
        return S.element[S.top];
    }
}
Stack push(Stack S, int x)
{
    if (isFull(S))
    {
        cout << "OVERFLOW \n";
    }
    else
    {
        S.element[++S.top] = x;
    }
    return S;
}

Stack pop(Stack S){
    if(isEmpty(S)){
        cout << "UNDERFLOW\n";

    }
    else{
        --S.top;
    }
    return S;
}

void print(Stack S){
int i;
for(i = S.top; i>=0 ; i--){
    cout << S.element[i] << endl;
}
}

int main()
{
   Stack S;
   S = init();
   S = push(S, 45);
   S = push(S, 10);
   S = push(S, 1);
   S = push(S, 50);
   cout << "Current Stack : " << endl;

   print(S);
   cout << " with top = " << topElement(S) << endl;
   S = pop(S);
   S = pop(S);
   cout << "Current Stack is: " << endl;
   print(S);
   cout <<  "with top element: " << endl;
   topElement(S);
   return 0;

}
