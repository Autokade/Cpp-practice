#include <bits/stdc++.h>
using namespace std;

void firstNonRepeatingChar(string str){
    unordered_map<char,int> charCount;
    queue<char> q;

    for(char c : str){
        charCount[c]++;
        q.push(c);

        while(!q.empty()){
            if(charCount[q.front()]>1){
                q.pop();
            }
            else{
                cout << q.front() << " ";
                break;
            }
        }
        if(q.empty()){
            cout << -1 << " ";
        }
    }
}


int main(){
    string str = "aabc";
    firstNonRepeatingChar(str);
    return 0;
}