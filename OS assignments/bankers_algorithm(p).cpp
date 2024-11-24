#include <bits/stdc++.h>
using namespace std;

void calculateNeed(vector<vector<int>> &need, vector<vector<int>> &max, vector<vector<int>> &allot, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }
}

void isSafe(vector<int> &processes, vector<int> &avail, vector<vector<int>> &max, vector<vector<int>> &allot, int n, int m) {
    vector<vector<int>> need(n, vector<int>(m));
    calculateNeed(need, max, allot, n, m);

    vector<bool> finish(n, false);
    vector<int> safeSeq;
    vector<int> work = avail;

    int count = 0;
    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                bool canAllocate = true;
                for (int j = 0; j < m; j++) {
                    if (need[p][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int k = 0; k < m; k++) {
                        work[k] += allot[p][k];
                    }
                    safeSeq.push_back(p);
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "System is not in a safe state.\n";
    
        }
        count++;
    }

    cout << "System is in a safe state.\nSafe Sequence is: ";
    for (int i = 0; i < safeSeq.size(); i++) {
        cout << "P" << safeSeq[i];
        if (i != safeSeq.size() - 1) {
            cout << " -> ";
        } else {
            cout << "\n";
        }
    }
}

int main() {
    int n = 5;
    int m = 3;

    vector<int> processes = {0, 1, 2, 3, 4};
    vector<int> avail = {3, 3, 2};

    vector<vector<int>> max = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {4, 2, 2},
        {5, 3, 3}
    };

    vector<vector<int>> allot = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    isSafe(processes, avail, max, allot, n, m);

    return 0;
}
