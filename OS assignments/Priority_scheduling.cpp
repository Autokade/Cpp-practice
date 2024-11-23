#include <bits/stdc++.h>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[], int priority[])
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (priority[j] > priority[j + 1])
            {
                swap(priority[j], priority[j + 1]);
                swap(bt[j], bt[j + 1]);
                swap(processes[j], processes[j + 1]);
            }
        }
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void findAvgTime(int processes[], int n, int bt[], int priority[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt, priority);

    findTurnAroundTime(processes, n, bt, wt, tat);

    cout << "Processes  " << "Burst Time  " << "Priority  "
         << "Waiting Time  " << "Turnaround Time\n";

    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << " " << processes[i] << "\t\t" << bt[i] << "\t    " << priority[i]
             << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
    }

    cout << "\nAverage waiting time = " << (float)total_wt / n;
    cout << "\nAverage turnaround time = " << (float)total_tat / n << "\n";
}

int main()
{
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {10, 5, 8};
    int priority[] = {3, 1, 2};

    findAvgTime(processes, n, burst_time, priority);

    return 0;
}
