#include<bits/stdc++.h>
using namespace std;

int linearSearc(int n, int num, vector<int> &arr){
    for (int i = 0; i < num; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
        
    }
    return -1;
    
}