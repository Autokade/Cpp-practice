#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingNumbers(vector<int>& arr1, vector<int>& arr2){
    unordered_set<int> set2(arr2.begin(), arr2.end());
    vector<int> result;

    for(int num : arr1){
        if(set2.find(num) == set2.end()){
            result.push_back(num);
        }
    }
    return result;
}

int main(){
    vector<int> arr1 = { 1,2,3,4,5,10};
    vector<int> arr2 = {2,3,1,0,5};

    vector<int> missing = findMissingNumbers(arr1, arr2);

    cout << "Numbers in first array but not in second: ";

    for(int num: missing){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}