#include <bits/stdc++.h>
using namespace std;

int main(){
    int cnt = 0;
    int n = 6;
    for (int i = 1; i < sqrt(n); i++)
    {
        if(n%i == 0){
            cnt = cnt + 1;
            if(n/i != i){
                cnt = cnt + 1;
            }
        }
    }
    if (cnt == 2){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}