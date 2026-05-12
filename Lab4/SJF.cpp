#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of Processes: ";
    cin >> n;

    vector<int> pid(n), arrival(n), burst(n), completion(n), turnaround(n), waiting(n);

    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        cout << "Arrival Time of Process " << i + 1 << ": ";
        cin >> arrival[i];
        cout << "Burst Time of Process " << i + 1 << ": ";
        cin >> burst[i];
    }

    // Sort processes
    vector<int> idx(n);
    for (int i = 0; i < idx.size(); i++)
    {
        idx[i] = i;
    }
    // sort(idx.begin(), idx.end(), [&](int a, int b)
    //      { return arrival[a] < arrival[b]; });
    for (int i = 0; i < idx.size() - 1; i++)
    {
        int minPos = i;
        for (int j = i + 1; j < idx.size(); j++)
        {
            if (arrival[idx[j]] < arrival[idx[minPos]])
            {
                minPos = j;
            }
        }

        // swap
        int temp = idx[i];
        idx[i] = idx[minPos];
        idx[minPos] = temp;
    }

    vector<int> sortedPid(n), sortedArrival(n), sortedBurst(n);
    for (int i = 0; i < n; i++)
    {
        sortedPid[i] = pid[idx[i]];
        sortedArrival[i] = arrival[idx[i]];
        sortedBurst[i] = burst[idx[i]];
    }

    vector<int> grantChart;
    int currentTime = 0;
    int idleTime = 0;
    int completed = 0;
    vector<bool> isCompleted(n, false);

    while (completed < n)
    {
        vector<pair<int, int>> readyQueue;

        for (int i = 0; i < n; i++)
        {
            if (sortedArrival[i] <= currentTime && !isCompleted[i])
            {
                readyQueue.push_back({sortedBurst[i], i});
            }
        }

        sort(readyQueue.begin(), readyQueue.end());

        if (readyQueue.empty())
        {
            // idle detect
            int nextArrival = INT_MAX;
            
            for (int i = 0; i < n; i++)
            {
                if (!isCompleted[i] && sortedArrival[i] > currentTime)
                {
                    nextArrival = min(nextArrival, sortedArrival[i]);
                }
            }

            idleTime += (nextArrival - currentTime);
            cout << endl;
            cout << "CPU Idle from " << currentTime << " to " << nextArrival << endl;
            currentTime = nextArrival;
            continue;
        }

        int idx2 = readyQueue[0].second;

        grantChart.push_back(sortedPid[idx2]);
        completion[idx2] = currentTime + sortedBurst[idx2];
        turnaround[idx2] = completion[idx2] - sortedArrival[idx2];
        waiting[idx2] = turnaround[idx2] - sortedBurst[idx2];
        currentTime = completion[idx2];
        isCompleted[idx2] = true;
        completed++;
    }
    // Output Results
    cout << endl
         << "Grant Chart" << endl;
    int abrar = grantChart.size();
    for (int i = 0; i < abrar; i++)
    {
        cout << "P" << grantChart[i] << "||";
    }
    cout << endl;
    cout << endl;
    cout << "Total Idle Time: " << idleTime << " units" << endl;
    float avgTurnaround = 0, avgWaiting = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Process " << sortedPid[i] << ": Arrival Time = " << sortedArrival[i] << ", Brust Time = " << sortedBurst[i] << ", Completion Time = " << completion[i] << ", Turnaround Time = " << turnaround[i] << ", Waiting Time = " << waiting[i] << endl;
        avgTurnaround += turnaround[i];
        avgWaiting += waiting[i];
    }
    avgTurnaround /= n;
    avgWaiting /= n;
    cout << "\nAverage Turnaround Time: " << avgTurnaround << endl;
    cout << "Average Waiting Time: " << avgWaiting << endl;

    return 0;
}
