 // Optimal Page Replacement Algorithm
#include <bits/stdc++.h>
using namespace std;

int main(){
    int page, frame; //page and frame size
    cout<<"Enter the number of pages and frame size: ";
    cin >> page >> frame;
    vector<int> pages(page);
    cout<<"Enter the pages: ";
    for (int i = 0; i < page; i++) {
        cin >> pages[i];
    }
    unordered_set<int> s; //to represent the set of current pages in memory
    int page_faults = 0;
    int hit = 0;
    // Traverse through page reference array
    for (int i = 0; i < page; i++) {
        if (s.size() < frame) {
            if (s.find(pages[i]) == s.end()) {
                s.insert(pages[i]);
                page_faults++; // Increment page fault count
            } else {
                hit++; // Increment hit count
            }
        } else { // If the set is full, we need to replace a page
            if (s.find(pages[i]) == s.end()) {
                int farthest = i, val;
                for (auto it : s) { // For each page in the set, find the farthest page to be used in future
                    int j;
                    for (j = i + 1; j < page; j++) {
                        if (pages[j] == it) {
                            if (j > farthest) { // Update farthest if this page is used farther in future
                                farthest = j;
                                val = it;
                            }
                            break;
                        }
                    }
                    if (j == page) { // If the page is not found in future, it is the farthest
                        val = it;
                        break;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
        }
    }
    cout << "Number of page faults: " << page_faults << endl;
    cout << "Number of page hits: " << hit << endl;
    return 0;
}