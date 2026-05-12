// Least Recent Used Replacement Algorithm Naive Approach
#include<bits/stdc++.h>
using namespace std;

int main(){
int page, frame;
cout<<"Enter number of pages: ";
cin>>page;
cout<<"Enter number of frames: ";
cin>>frame;
vector<int> pages(page);
cout<<"Enter the page numbers: ";
for(int i=0; i<page; i++){
    cin>>pages[i];
}
unordered_set<int> s; // To represent the set of current pages in memory
unordered_map<int, int> indexes; // To store the most recent index of each page in memory
int page_faults = 0;
int hits = 0;

for(int i=0; i<page; i++){
    // empty check
    if(s.size() < frame){
        // Miss Check
        if(s.find(pages[i]) == s.end()){
            s.insert(pages[i]); //page insert korbo 
            page_faults++; //miss count barabo
        }
        //index of the page
        indexes[pages[i]] = i;
    }
    // hit check korbo
    else{
        // miss check
        if(s.find(pages[i]) == s.end()){
            int lru = 1000000, val;
            // LRU condition check
            for(auto it : s){
                if(indexes[it] < lru){ // If the index of the page is less than the least recently used page
                    lru = indexes[it]; // Update the least recently used page index
                    val = it; // Update the value of the least recently used page 
                }
            }
            // Remove least value
            s.erase(val);
            // replace new page
            s.insert(pages[i]);
            page_faults++;
        }
        // miss na hole hit count barabo
        else{
            hits++;
        }
        // Update the index of the page
        indexes[pages[i]] = i;
    }
    cout<<"Page: "<<pages[i]<<" | Page Faults: "<<page_faults<<" | Hits: "<<hits<<endl;
    cout<<"Current Pages in Frame: ";
    for(auto it : s){
        cout<<it<<" ";
    }
    cout<<endl;
}
cout<<"Total Page Faults: "<<page_faults<<endl;
cout<<"Total Hits: "<<hits<<endl;

return 0;
}