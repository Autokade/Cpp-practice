#include <iostream>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[]){
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i-1] + wt[i-1];
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]){
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void findAvgTime(int processes[], int n, int bt[]){
    int total_wt = 0, total_tat = 0, wt[n], tat[n];

    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    cout << "Processes " << " burst time " << " Waiting time " << " Turn around time" << endl;

    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;

    }

    cout <<"average waiting time - " <<  (float)total_wt/(float)n;
    cout << "average turn around time - " << (float)total_tat/(float)n;
}

int main(){
    int processes[] = {1,2,3};
    int n = sizeof processes / sizeof processes[0];

    int burst_time[] = {10,5,8};
    findAvgTime(processes, n, burst_time);
    return 0; 
}