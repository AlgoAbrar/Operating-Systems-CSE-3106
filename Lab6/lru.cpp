// Least Recet Used Page Replacement Algorithm
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, capacity;
    cin >> n >> capacity;
    vector<int> pages(n);
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    unordered_set<int> s;
    unordered_map<int, int> indexes;
    int page_faults = 0;
    for (int i = 0; i < n; i++) {
        if (s.size() < capacity) {
            if (s.find(pages[i]) == s.end()) {
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        } else {
            if (s.find(pages[i]) == s.end()) {
                int lru = INT_MAX, val;
                for (auto it : s) {
                    if (indexes[it] < lru) {
                        lru = indexes[it];
                        val = it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        }
    }
    cout << page_faults << endl;
    return 0;
}