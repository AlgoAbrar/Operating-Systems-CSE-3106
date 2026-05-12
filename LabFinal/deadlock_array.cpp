#include <iostream>
using namespace std;

int main() {
    int n, r;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> r;

    int alloc[n][r], maxm[n][r], need[n][r];
    int avail[r];
    int finished[n] = {0};
    int safeSeq[n];

    // Allocation matrix
    cout << "Enter Allocation Matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i << ": ";
        for (int j = 0; j < r; j++) {
            cin >> alloc[i][j];
        }
    }

    // Max matrix
    cout << "Enter Max Matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i << ": ";
        for (int j = 0; j < r; j++) {
            cin >> maxm[i][j];
        }
    }

    // Available
    cout << "Enter Available Resources: ";
    for (int j = 0; j < r; j++) {
        cin >> avail[j];
    }

    // Calculate Need = Max - Allocation
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = maxm[i][j] - alloc[i][j];

    int index = 0;

    // Safety Algorithm
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
                    safeSeq[index++] = i;

                    for (int j = 0; j < r; j++)
                        avail[j] += alloc[i][j];

                    finished[i] = 1;
                }
            }
        }
    }

    // Output
    if (index == n) {
        cout << "Safe Sequence: ";
        for (int i = 0; i < n; i++) {
            cout << "P" << safeSeq[i];
            if (i != n - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "System is NOT in safe state\n";
    }

    return 0;
}