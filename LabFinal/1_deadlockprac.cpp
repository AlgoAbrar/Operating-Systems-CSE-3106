#include<bits/stdc++.h>
using namespace std;


int main(){

    int processes, resources;
    cout<<"Enter the number of processes: ";
    cin>> processes;
    cout<<"Enter the number of resources: ";
    cin>> resources;

    int alloc[processes][resources], maxm[processes][resources], need[processes][resources];
    int avail[resources];
    int finished[processes]={0};
    int safeseq[processes];
    cout<<"Enter Allocation Matrix: "<<endl;
    for(int i=0; i<processes; i++){
        cout<<"P"<<i+1<<": ";
        for(int j=0; j<resources;j++){
            cin>>alloc[i][j];
        }
    }

    cout<<"Enter Maximum Matrix: "<<endl;
    for(int i=0; i<processes; i++){
        cout<<"P"<<i+1<<": ";
        for(int j=0; j<resources;j++){
            cin>>maxm[i][j];
        }
    }
    cout<<"Enter Available Resources: "<<endl;
    for(int i=0; i<resources; i++){
        cin>>avail[i];
    }

    //need matrix
    for(int i=0;i<processes; i++){
        for(int j=0; j<resources; j++){
            need[i][j] = maxm[i][j] - alloc[i][j];
        }
    }

    //bankers algorithm
    int count= 0;
    int index =0;
    for(int k=0; k<processes; k++){
        for(int i=0; i<processes; i++){
            if(finished[i] == 0){
                bool canRun = true;
                for(int j=0; j<resources; j++){
                    if(need[i][j] > avail[j]){
                        canRun = false;
                        break;
                    }
                }
                if(canRun){
                    safeseq[index++] = i;
                    for(int y=0; y<resources; y++){
                        avail[y] += alloc[i][y];
                    }
                    finished[i] = 1;
                    count++;
                }
            }
        }
    }

    //output
    if (index == processes) {
        cout << "Safe Sequence: ";
        for (int i = 0; i < processes; i++) {
            cout << "P" << safeseq[i];
            if (i != processes - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "System is NOT in safe state\n";
    }

}