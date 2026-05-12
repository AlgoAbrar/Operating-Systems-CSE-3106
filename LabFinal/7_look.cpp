#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

int main() {

    int n;

    int addresses[MAX];

    // Input number of requests
    cout << "Enter number of requests: ";
    cin >> n;

    // Input requests
    cout << "Enter the requests: ";

    for (int i = 0; i < n; i++) {
        cin >> addresses[i];
    }

    int head;

    cout << "Enter head position: ";
    cin >> head;

    // Sort requests
    sort(addresses, addresses + n);

    int totalMovement = 0;
    int current = head;

    int sequence[MAX + 10];
    int seqSize = 0;

    // Add initial head
    sequence[seqSize++] = head;

    // Move Right First (LOOK)
    for (int i = 0; i < n; i++) {

        if (addresses[i] >= head) {

            totalMovement += abs(current - addresses[i]);

            current = addresses[i];

            sequence[seqSize++] = current;
        }
    }

    // Move Left
    for (int i = n - 1; i >= 0; i--) {

        if (addresses[i] < head) {

            totalMovement += abs(current - addresses[i]);

            current = addresses[i];

            sequence[seqSize++] = current;
        }
    }

    // Output
    cout << "\nTotal head movement (LOOK): "
         << totalMovement << endl;

    cout << "Sequence: ";

    for (int i = 0; i < seqSize; i++) {
        cout << sequence[i] << " ";
    }

    cout << endl;

    return 0;
}


// '''
// number of request: 7
// Sample Input: 82 170 43 140 24 16 190
// head 50
// max track number: 200

// '''