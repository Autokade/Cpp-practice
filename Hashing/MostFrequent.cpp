#include <bits/stdc++.h>
using namespace std;


int findMostFrequent(vector<int>& arr){
    if(arr.empty()){
        return -1;
    }

    unordered_map<int,int> frequency;

    int maxFreq = 0;
    int mostFrequent = arr[0];

    for(int num : arr){
        frequency[num]++;
        if(frequency[num] > maxFreq){
            maxFreq = frequency[num];
            mostFrequent = num;
        }
    }

    return mostFrequent;
}

int main(){
    vector<int> arr = {1,3,2,1,4,1};

    cout << "Most frequent element: " << findMostFrequent(arr) << endl;
    return 0;
}