#include <bits/stdc++.h>
using namespace std;

bool findPairSumHash(vector<int>& arr, int target){

    unordered_set<int> seen;

    for(int num : arr){
        int complement = target - num;

        if(seen.find(complement) != seen.end()){
            cout << "Pair found: " << complement << " + " << num << endl;
            return true;
        }
        seen.insert(num);
    }
    return false;
}


int main(){
    vector<int> arr = {1,4,45,6,10,-8};
    int target = 16;

    cout << "Using hash set method: \n" ;
    findPairSumHash(arr,target);

    return 0;
}