#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    for (int i = n; i >= 0; i--)
    {
        for (int j = n - i - 1; j >= 0; j--)
        {
            cout << " ";
        }
        for (int j = 2 * i ; j >= 0; j--)
        {
            cout << "*";
        }
        for (int j = n - i - 1; j >= 0; j--)
        {
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}