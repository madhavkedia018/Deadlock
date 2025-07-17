#include <iostream>
#include <vector>

using namespace std;

bool isSafeState(const vector<vector<int>>& allocation,
                 const vector<vector<int>>& max,
                 const vector<int>& available,
                 vector<int>& safeSequence) {
    int n = allocation.size();     // number of processes
    int m = available.size();      // number of resource types

    vector<vector<int>> need(n, vector<int>(m));
    vector<int> work = available;
    vector<bool> finish(n, false);

    // Calculate Need Matrix
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            need[i][j] = max[i][j] - allocation[i][j];

    // Banker's Algorithm
    int count = 0;
    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; ++i) {
            if (!finish[i]) {
                bool canProceed = true;
                for (int j = 0; j < m; ++j) {
                    if (need[i][j] > work[j]) {
                        canProceed = false;
                        break;
                    }
                }

                if (canProceed) {
                    for (int j = 0; j < m; ++j)
                        work[j] += allocation[i][j];

                    safeSequence.push_back(i);
                    finish[i] = true;
                    found = true;
                    ++count;
                }
            }
        }

        if (!found) {
            return false; // no safe sequence found
        }
    }

    return true;
}

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resource types: ";
    cin >> m;

    vector<vector<int>> allocation(n, vector<int>(m));
    vector<vector<int>> max(n, vector<int>(m));
    vector<int> available(m);

    cout << "\nEnter Allocation Matrix (process by process):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Process P" << i << ": ";
        for (int j = 0; j < m; ++j)
            cin >> allocation[i][j];
    }

    cout << "\nEnter Max Matrix (process by process):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Process P" << i << ": ";
        for (int j = 0; j < m; ++j)
            cin >> max[i][j];
    }

    cout << "\nEnter Available Resources: ";
    for (int j = 0; j < m; ++j)
        cin >> available[j];

    vector<int> safeSequence;

    if (isSafeState(allocation, max, available, safeSequence)) {
        cout << "\n✅ System is in a SAFE STATE.\n";
        cout << "Safe sequence: ";
        for (int i = 0; i < safeSequence.size(); ++i)
            cout << "P" << safeSequence[i] << (i == safeSequence.size() - 1 ? "\n" : " → ");
    } else {
        cout << "\n❌ DEADLOCK possible! No safe sequence exists.\n";
    }

    return 0;
}
