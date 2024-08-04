#include<bits/stdc++.h>
using namespace std;

int main(){
int cnt = 0;
int n = 123;
while (n>0)
{
    int lastDigit = n%10;
    cnt = cnt + 1;
    n = n/10;

}
cout << cnt;

}
