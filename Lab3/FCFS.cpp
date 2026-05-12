#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of Processes: ";
    cin >> n;
    vector<int> processid(n), arrival(n), brust(n), completion(n), turnaround(n), waiting(n);
    for (int i = 0; i < n; i++)
    {
        processid[i] = i + 1;
        cout << "Arrival Time of Process " << i + 1 << ": ";
        cin >> arrival[i];
        //arrival[i] = 0;
        cout << "Brust Time of Process " << i + 1 << ": ";
        cin >> brust[i];
    }
    
    for(int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arrival[j] > arrival[j + 1])
            {
                swap(arrival[j], arrival[j + 1]);
                swap(brust[j], brust[j + 1]);
                swap(processid[j], processid[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            completion[i] = arrival[i] + brust[i];
        }
        else
        {
            if (arrival[i] > completion[i - 1])
            {
                completion[i] = arrival[i] + brust[i];
            }
            else
            {
                completion[i] = completion[i - 1] + brust[i];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - brust[i];
        cout << "Process " << processid[i] << ": Arrival Time = " << arrival[i] << ", Brust Time = " << brust[i] << ", Completion Time = " << completion[i] << ", Turnaround Time = " << turnaround[i] << ", Waiting Time = " << waiting[i] << "\n";
    }
}