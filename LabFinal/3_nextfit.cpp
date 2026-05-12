#include <iostream>
using namespace std;

const int MAX = 10;

int main() {

    int blockSize[MAX];
    int processSize[MAX];

    bool blockAllocated[MAX] = {false};
    int allocation[MAX];

    int totalInternalFrag = 0;
    int totalExternalFrag = 0;

    int nBlocks, nProcesses;

    // Input number of blocks
    cout << "Enter number of memory blocks: ";
    cin >> nBlocks;

    // Input block sizes
    cout << "Enter sizes of memory blocks:\n";

    for (int i = 0; i < nBlocks; i++) {
        cout << "Block " << i + 1 << ": ";
        cin >> blockSize[i];
    }

    // Input number of processes
    cout << "\nEnter number of processes: ";
    cin >> nProcesses;

    // Input process sizes
    cout << "Enter sizes of processes:\n";

    for (int i = 0; i < nProcesses; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> processSize[i];

        allocation[i] = -1;
    }

    // Next Fit Allocation
    int lastAllocatedIndex = 0;

    for (int i = 0; i < nProcesses; i++) {

        int count = 0;
        int j = lastAllocatedIndex;

        while (count < nBlocks) {

            // Check free block and enough size
            if (!blockAllocated[j] &&
                blockSize[j] >= processSize[i]) {

                allocation[i] = j;
                blockAllocated[j] = true;

                // Internal Fragmentation
                totalInternalFrag +=
                    blockSize[j] - processSize[i];

                // Start next search from next block
                lastAllocatedIndex = (j + 1) % nBlocks;

                break;
            }

            // Circular traversal
            j = (j + 1) % nBlocks;
            count++;
        }
    }

    // Output
    cout << "\nProcess No.\tProcess Size\tBlock No.\n";

    for (int i = 0; i < nProcesses; i++) {

        cout << i + 1 << "\t\t"
             << processSize[i] << "\t\t";

        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";

        cout << endl;
    }

    // Print Internal Fragmentation
    cout << "\nTotal Internal Fragmentation: "
         << totalInternalFrag << endl;

    // Calculate External Fragmentation
    for (int i = 0; i < nBlocks; i++) {

        if (!blockAllocated[i]) {
            totalExternalFrag += blockSize[i];
        }
    }

    // Print External Fragmentation
    cout << "Total External Fragmentation: "
         << totalExternalFrag << endl;

    return 0;
}