#include <bits/stdc++.h>
using namespace std;

int sum (int n){
    
    if(n<1){
        return 0;
    }

    return n + sum(n-1);
}
int main(){
    int ans = sum(5);
    cout<<ans;
    return 0;
}