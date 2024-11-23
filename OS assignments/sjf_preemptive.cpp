#include <bits/stdc++.h>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[],int at[]){
    int remaining_bt[n];
    for (int i = 0; i < n; i++)
    {
        remaining_bt[i] = bt[i];
    }

    int completed = 0, current_time = 0, min_bt = INT_MAX;
    bool found = false;
    int shortest = 0, finish_time;

    while(completed != n){
        for (int j = 0; j < n; j++)
        {
            if(at[j] <= current_time && remaining_bt[j] > 0 && remaining_bt[j] < min_bt){
                min_bt = remaining_bt[j];
                shortest = j;
                found = true;

            }
        }
        if(!found){
            current_time++;
            continue;
        }
        remaining_bt[shortest]--;
        min_bt = remaining_bt[shortest];

        if(min_bt == 0){
            min_bt = INT_MAX;
        }
        if(remaining_bt[shortest] == 0){
            completed++;
            found = false;

            finish_time = current_time + 1;

            wt[shortest] = finish_time - bt[shortest] - at[shortest];
            if(wt[shortest]<0){
                wt[shortest] = 0;
            }
        }
        current_time++;
    }
}


void findTurnAroundTime(int processesp[], int n, int bt[], int wt[], int tat[]){
    for (int i = 0; i < n; i++)
    {
        tat[i]=  bt[i] + wt[i];
    }
    
}


void findAvgTime(int processes[], int n, int bt[],int at[]){
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt, at);

    findTurnAroundTime(processes, n, bt, wt, tat);


    cout << "processes " << " Burst Time" <<  " Waiting Time " << " Turn around time \n" << endl;


    for(int i = 0; i < n ; i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 <<  "\t\t" << bt[i] << "\t  " << wt[i] << "\t\t " << tat[i] << endl;
    } 

    cout << "Average waiting time = " << (float)total_wt/(float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}


int main(){
    int processes[] = {1,2,3};
    int n = sizeof processes / sizeof processes[0];

    int burst_time[] = {10,5,8};

    int arrival_time[] = {0,1,2};

    findAvgTime(processes, n, burst_time, arrival_time);
    return 0;
}

