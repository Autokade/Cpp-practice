#include <bits/stdc++.h>
using namespace std;

class StackWithOneQueue
{
    queue<int> q;

public:
    void push(int x)
    {
        int size = q.size();
        q.push(x);

        for (int i = 0; i < size; ++i)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        if (q.empty())
        {
            cout << "stack is empty" << endl;
            return;
        }
        q.pop();
    }
    int top()
    {
        if (q.empty())
        {
            cout << "stack is empty \n";
            return -1;
        }
        return q.front();
    }
    bool Empty()
    {
        return q.empty();
    }
};


int main(){
    StackWithOneQueue stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top();
    return 0;
    
    }