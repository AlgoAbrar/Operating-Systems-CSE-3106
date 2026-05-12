#include <iostream>
using namespace std;

const int MAX = 50;

int main() {

    int n, f;

    int pages[MAX];
    int frames[MAX];

    int miss = 0;
    int hit = 0;

    int idx = 0;

    // Input number of pages
    cout << "Enter number of pages: ";
    cin >> n;

    // Input page reference string
    cout << "Enter page reference string: ";

    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    // Input number of frames
    cout << "Enter number of frames: ";
    cin >> f;

    // Initialize frames with -1
    for (int i = 0; i < f; i++) {
        frames[i] = -1;
    }

    // FIFO Page Replacement
    for (int i = 0; i < n; i++) {

        bool found = false;

        // Check HIT
        for (int j = 0; j < f; j++) {

            if (frames[j] == pages[i]) {
                found = true;
                hit++;
                break;
            }
        }

        // MISS
        if (!found) {

            frames[idx] = pages[i];

            // Circular index
            idx = (idx + 1) % f;

            miss++;

            cout << "Page " << pages[i]
                 << " -> FAULT -> ";
        }
        else {

            cout << "Page " << pages[i]
                 << " -> HIT   -> ";
        }

        // Print frames
        for (int j = 0; j < f; j++) {
            cout << frames[j] << " ";
        }

        cout << endl;
    }

    // Output
    cout << "\nPage Miss = " << miss << endl;
    cout << "Page Hits = " << hit << endl;

    return 0;
}