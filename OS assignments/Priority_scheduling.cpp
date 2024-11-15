#include <bits/stdc++.h>
using namespace std;

#define totalprocess 5


struct process{
    int at, bt, pr, pno;

};

process proc[50];


bool comp(process a, process b){
    if(a.at == b.at){
        return a.pr<b.pr;
    }
    else{
        return a.at<b.at;
    }
}

void get_wt_time(int wt[]){
    int service[50];

    service[0] = proc[0].at;
    wt[0] = 0;
}