#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, r;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> r;

    vector<vector<int>> alloc(n, vector<int>(r));
    vector<vector<int>> maxm(n, vector<int>(r));
    vector<int> avail(r);

    // Allocation matrix input
    cout << "Enter Allocation Matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i << ": ";
        for (int j = 0; j < r; j++) {
            cin >> alloc[i][j];
        }
    }

    // Max matrix input
    cout << "Enter Max Matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i << ": ";
        for (int j = 0; j < r; j++) {
            cin >> maxm[i][j];
        }
    }

    // Available resources
    cout << "Enter Available Resources: ";
    for (int j = 0; j < r; j++) {
        cin >> avail[j];
    }

    // --- Banker's Algorithm starts ---
    vector<vector<int>> need(n, vector<int>(r));
    vector<int> finished(n, 0), safeSeq;

    // Need = Max - Allocation
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = maxm[i][j] - alloc[i][j];

    // Safety check
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (!finished[i]) {
                bool canRun = true;

                for (int j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        canRun = false;
                        break;
                    }
                }

                if (canRun) {
                    safeSeq.push_back(i);

                    for (int j = 0; j < r; j++)
                        avail[j] += alloc[i][j];

                    finished[i] = 1;
                }
            }
        }
    }

    // Output
    if (safeSeq.size() == n) {
        cout << "Safe Sequence: ";
        for (int i = 0; i < n; i++) {
            cout << "P" << safeSeq[i];
            if (i != n - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "System is NOT in a safe state\n";
    }

    return 0;
}