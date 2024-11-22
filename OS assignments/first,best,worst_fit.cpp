#include <vector>
#include <iostream>
#include <climits>

using namespace std;

void firstFit(vector<int> memory, vector<int> processes)
{
    cout << "\nFirst Fit Allocation: \n";

    vector<int> allocation(processes.size(), -1);

    for (int i = 0; i < processes.size(); i++)
    {
        for (int j = 0; j < memory.size(); j++)
        {
            if (memory[j] >= processes[i])
            {
                allocation[i] = j;
                memory[j] -= processes[i];
                break;
            }
        }
    }

    for (int i = 0; i < processes.size(); i++)
    {
        cout << "Process " << i + 1 << " (" << processes[i] << " KB) -> ";
        if (allocation[i] != -1)
        {
            cout << "Block " << allocation[i] + 1 << endl;
        }
        else
        {
            cout << "Not Allocated\n";
        }
    }
}

void bestFit(vector<int> memory, vector<int> processes)
{
    cout << "\n Best Fit Allocation: \n";

    vector<int> allocation(processes.size(), -1);

    for (int i = 0; i < processes.size(); i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < memory.size(); j++)
        {
            if (memory[j] >= processes[i])
            {
                if (bestIdx == -1 || memory[j] < memory[bestIdx])
                {
                    bestIdx = j;
                }
            }

            if (bestIdx != -1)
            {
                allocation[i] = bestIdx;
                memory[bestIdx] -= processes[i];
            }
        }

        for (int i = 0; i < processes.size(); i++)
        {
            cout << "Process " << i + 1 << " (" << processes[i] << "KB) -> ";
            if (allocation[i] != -1)
            {
                cout << "Block " << allocation[i] + 1 << endl;
            }
            else
            {
                cout << "Not Allocated\n";
            }
        }
    }
}

void worstFit(vector<int> memory, vector<int> processes)
{
    cout << "\nWorst Fit Allocation: \n";
    vector<int> allocation(processes.size(), -1);

    for (int i = 0; i < processes.size(); i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < memory.size(); j++)
        {
            if (memory[j] >= processes[i])
            {
                if (worstIdx == -1 || memory[j] > memory[worstIdx])
                {
                    worstIdx = j;
                }
            }
            if (worstIdx != -1)
            {
                allocation[i] = worstIdx;
                memory[worstIdx] -= processes[i];
            }
        }
    }
    for (int i = 0; i < processes.size(); i++)
    {
        cout << "Process " << i + 1 << " (" << processes[i] << " KB) ->";
        if (allocation[i] != -1)
        {
            cout << "block " << allocation[i] << endl;
        }
        else
        {
            cout << "Not Allocated\n";
        }
    }
}