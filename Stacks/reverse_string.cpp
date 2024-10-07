#include <bits/stdc++.h>
using namespace std;

string reverseString(string str){
    stack<char> charStack;

    for(char c : str ){
        charStack.push(c);
    }

    string reversedStr = "";
    while (!charStack.empty())
    {
        reversedStr += charStack.top();
        charStack.pop();
    }

    return reversedStr;
    
}

int main(){
    string str = "DataStructure";
    cout << "Original string: " << str << endl;

    string reversedStr = reverseString(str);
    cout << "Reversed String: " << reversedStr << endl;
    return 0;
}