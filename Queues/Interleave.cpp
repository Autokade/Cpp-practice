#include <bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &q)
{
    int n = q.size();
    queue<int> firstHalf, secondHalf;

    for (int i = 0; i < n / 2; i++)
    {
        firstHalf.push(q.front());
        q.pop();
    }

    for (int i = n / 2; i < n; i++)
    {
        secondHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty())
    {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(secondHalf.front());
        secondHalf.pop();
    }
}