#include <bits/stdc++.h>
using namespace std;

void Insert(vector<int> &A, int n){
    int i = n, temp = A[i];
    while(i>1 && temp > A[i/2]){
        A[i] = A[i/2];
        i = i/2;

    }
    A[i] = temp;
}

int Delete(vector<int> &A, int n ){
    int i = 1, j = 2*i, val = A[1], x = A[n];
    A[1] = A[n];
    A[n] = val;\

    while(j<n){
        if(j<n-1 && A[j + 1]){
            j++;
        }
        if(A[i] < A[j]){
            swap(A[i], A[j]);
            i = j;
            j = 2*j;

        }
        else{
            break;
        }

    }
    return val;
}


int main(){
    vector<int> H = {0,14,15,5,20,30,8,40};

    for(int i = 2; i < H.size(); i++){
        Insert(H,i);
    }

    for(int i = H.size()- 1; i>1; i--){
        Delete(H,i);
    }

    for(int i = 1;i<H.size();i++){
        cout << H[i] << " ";
        cout << endl;

    }
        return 0;
}