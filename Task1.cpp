//#include <iostream>
//#include <queue>
//#include <string>
//
//using namespace std;
//
//struct Process {
//    string processName;
//    int arrivalTime;
//    int burstTime;
//};
//
//void RoundRobin(Process processes[], int n, int timeQuantum) {
//    queue<int> processQueue; 
//    int remainingBurstTime[n],completionTime[n],i=0; 
//
//while(i<n){
//            remainingBurstTime[i] = processes[i].burstTime;
//        completionTime[i] = -1; 
//        i++;
//}
//
//    int currentTime = 0;
//
//    while (true) {
//        bool allProcessesCompleted = true;
//
//        for ( i = 0; i < n; ++i) {
//            if (remainingBurstTime[i] > 0) {
//                allProcessesCompleted = false;
//
//                if (remainingBurstTime[i] > timeQuantum) {
//                    currentTime += timeQuantum;
//                    remainingBurstTime[i] -= timeQuantum;
//                } else {
//                    currentTime += remainingBurstTime[i];
//                    remainingBurstTime[i] = 0;
//                    completionTime[i] = currentTime; // Update completion time
//                }
//
//                while (i < n && processes[i].arrivalTime <= currentTime) {
//                    processQueue.push(i);
//                    ++i;
//                }
//            }
//        }
//
//        if (allProcessesCompleted) {
//            break;
//        }
//
//        while (!processQueue.empty()) {
//            int frontProcess = processQueue.front();
//            processQueue.pop();
//
//            if (remainingBurstTime[frontProcess] > 0) {
//                processQueue.push(frontProcess);
//                break;
//            }
//        }
//    }
//
//
//    for (int i = 0; i < n; ++i) {
//        cout << "Process " << processes[i].processName << " completed at time " << completionTime[i] << endl;
//    }
//}
//
//int main() {
//    int n,timeQuantum;
//    cout << "Enter the number of processes: ";cin >> n;
//
//    Process processes[n];
//
//    for (int i = 0; i < n; ++i) {
//        cout << "Enter details for Process " << i + 1 << ":" << endl;
//        cout << "Name: ";cin >> processes[i].processName;
//        cout << "Arrival Time: ";cin >> processes[i].arrivalTime;
//        cout << "Burst Time: ";cin >> processes[i].burstTime;
//    }
//    cout << "Enter the time quantum: ";cin >> timeQuantum;
//    RoundRobin(processes, n, timeQuantum);
//
//    return 0;
//}
