#include <iostream>
using namespace std;

const int MAX = 50;

int main() {

    int n, f;

    int pages[MAX];
    int frames[MAX];
    int order[MAX];

    int orderSize = 0;

    int hit = 0;
    int miss = 0;

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

    // LRU Page Replacement
    for (int i = 0; i < n; i++) {

        int page = pages[i];
        bool found = false;

        // Check HIT
        for (int j = 0; j < f; j++) {

            if (frames[j] == page) {
                found = true;
                hit++;

                cout << "Page " << page
                     << " -> HIT   -> ";

                // Remove page from order
                int pos = -1;

                for (int k = 0; k < orderSize; k++) {
                    if (order[k] == page) {
                        pos = k;
                        break;
                    }
                }

                if (pos != -1) {
                    for (int k = pos; k < orderSize - 1; k++) {
                        order[k] = order[k + 1];
                    }
                    orderSize--;
                }

                // Add as most recent
                order[orderSize++] = page;

                break;
            }
        }

        // MISS / PAGE FAULT
        if (!found) {

            miss++;

            cout << "Page " << page
                 << " -> FAULT -> ";

            bool emptyFound = false;

            // Check empty frame
            for (int j = 0; j < f; j++) {

                if (frames[j] == -1) {
                    frames[j] = page;
                    emptyFound = true;
                    break;
                }
            }

            // Replace LRU page
            if (!emptyFound) {

                int lruPage = order[0];

                // Remove first element from order
                for (int k = 0; k < orderSize - 1; k++) {
                    order[k] = order[k + 1];
                }
                orderSize--;

                // Find and replace LRU page
                for (int j = 0; j < f; j++) {

                    if (frames[j] == lruPage) {
                        frames[j] = page;
                        break;
                    }
                }
            }

            // Add new page as most recent
            order[orderSize++] = page;
        }

        // Print frame status
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