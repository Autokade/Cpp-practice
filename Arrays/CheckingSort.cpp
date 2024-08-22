#include <bits/stdc++.h>
using namespace std;

int isSorted(int n, vector<int> a)
{
    for (int i = 1; i < n; i++)
    {
        /* code */
        if (a[i] > a[i - 1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
}