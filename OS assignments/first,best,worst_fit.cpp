#include<vector>
#include<iostream>
#include<climits>

using namespace std;

void firstFit(vector<int> memory, vector<int> processes){
    cout << "\nFirst Fit Allocation: \n";

    vector<int> allocation(processes.size(), -1);


    for(int i = 0; i<processes.size(); i++){
        for(int j =0; j < memory.size(); j++){
            if(memory[j]>= processes[i]){
                allocation[i] = j;
                memory[j] -= processes[i];
                break;
            }
        }
    }

    for(int i = 0; i < processes.size(); i++){
        cout << "Process " << i+1 << " (" << processes[i] << " KB) -> ";
        if(allocation[i] != -1){
            cout << "Block " << allocation[i] + 1 << endl;

        }
        else{
            cout << "Not Allocated\n";
        }
    }
}