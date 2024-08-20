#include <bits/stdc++.h>
using namespace std;

int main(){
    int sum = 0;
    int x=370;
    int original = x;
    while(x>0){
        int lastDigit = x%10;
        sum = sum + (lastDigit * lastDigit * lastDigit);
        x = x / 10;
    } 
    if(sum == original){
        cout << sum << endl;
        cout << "True";
    }
    else{
        cout << "False";
    }
    return 0;
}