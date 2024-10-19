#include <bits/stdc++.h>
using namespace std;

void InsertA(int A[], int n){
    int i = n;
    int temp = A[n];
    while(i > 1 && temp > A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}


template < class T >
void Print(T &vec, int n){
    cout << "Max Heap: {" << flush;
    for(int i=0; i< n; i++){
        cout <<vec[i] << flush;
        if(i<n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

int main() {
 
    int a[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};
    InsertA(a, 9);
    Print(a, sizeof(a)/sizeof(a[0]));
    cout << endl;
 
    return 0;
}