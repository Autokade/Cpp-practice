#include <bits/stdc++.h>
using namespace std;

void reverse(int *a,int l, int r){
    if(l>=r){
        return;
    }
    swap(a[l],a[r]);
    reverse(a,l+1,r-1);
}

int main(){
    int arr[]={1,2,3,4,5};
    reverse(arr,0,4);
    for(int i=0;i<5;i++){
            cout<<arr[i];
    }

}