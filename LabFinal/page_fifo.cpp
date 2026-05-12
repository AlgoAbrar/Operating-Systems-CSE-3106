#include <bits/stdc++.h>
using namespace std;

int main() {
    int pages[100], frames[100];
    int n, f;

    cout << "Enter number of pages: ";
    cin >> n;

    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter number of frames: ";
    cin >> f;

    for (int i = 0; i < f; i++) {
        frames[i] = -1;
    }

    int miss = 0,hit=0;
    int idx = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;

        // HITT
        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                hit++;
                break;
            }
        }

        if (found == 0) {
            // MISS
            frames[idx] = pages[i];
            idx = (idx + 1) % f;
            miss++;
            cout << "Page " << pages[i] << " -> FAULT -> ";
        } else {
            cout << "Page " << pages[i] << " -> HIT   -> ";
        }

        // Page Status
        for (int j = 0; j < f; j++) {
            if (frames[j] == -1)
                cout << "-1 ";
            else
                cout << frames[j] << " ";
        }
        cout << endl;
    }

    cout << "\nPage Miss = " << miss << endl;
    cout << "Page Hits = " << hit << endl;

    return 0;
}