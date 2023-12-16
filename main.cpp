#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Define Process Structure
struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
    int priority;
    // Add other necessary attributes

    Process(int pid, int at, int bt, int pri) : processID(pid), arrivalTime(at), burstTime(bt), priority(pri) {}
};

// Define MLQ Structure
class MultilevelQueue {
private:
    static const int MAX_QUEUE = 5; // Maximum number of priority queues
    vector<queue<Process>> queues; // Vector of queues
    
    // Function to promote processes in lower-priority queues
    // Function to promote processes in lower-priority queues based on time
void priorityPromotion() {
    const int TIME_THRESHOLD = 5; // Threshold for priority promotion (in simulation steps)

    for (int i = 1; i < MAX_QUEUE; ++i) {
        int queueSize = queues[i].size();
        for (int j = 0; j < queueSize; ++j) {
            Process p = queues[i].front();
            queues[i].pop();

            // Increment the waiting time for the process
            p.arrivalTime++;

            // Check if the process has waited beyond the time threshold
            if (p.arrivalTime >= TIME_THRESHOLD) {
                p.arrivalTime = 0; // Reset the waiting time for promoted process
                p.priority--; // Promote the process to a higher-priority queue
                if (p.priority < 0) {
                    p.priority = 0; // Ensure priority doesn't go below the lowest priority
                }
            }

            // Enqueue the process to the new priority queue after potential promotion
            queues[p.priority].push(p);
        }
    }
}

public:
    MultilevelQueue() {
        queues.resize(MAX_QUEUE); // Resize the vector of queues
    }

    // Function to enqueue a process based on priority
    void enqueueProcess(Process p) {
        queues[p.priority].push(p);
    }

    // Function to dequeue a process from the highest priority queue
    Process dequeueProcess() {
        for (int i = 0; i < MAX_QUEUE; ++i) {
            if (!queues[i].empty()) {
                Process p = queues[i].front();
                queues[i].pop();
                return p;
            }
        }
        // If all queues are empty, return an empty process or handle accordingly
        Process emptyProcess(-1, -1, -1, -1); // Placeholder for an empty process
        return emptyProcess;
    }

    // Function to simulate CPU scheduling
    void simulateScheduling() {
        // Simulate scheduling logic here
        while (true) {
            Process p = dequeueProcess();
            if (p.processID == -1) {
                // No more processes to execute
                cout << "All processes executed." << endl;
                break;
            }
            cout << "Executing Process " << p.processID << " from Queue " << p.priority << endl;
            // Simulate execution by waiting for burst time (sleep function or any other mechanism)
        }
    }
};

int main() {
    MultilevelQueue mlq;

    // Example: Adding processes to the queues
    Process p1(1, 0, 10, 0); // Process with ID 1, arrival time 0, burst time 10, priority 0
    Process p2(2, 1, 8, 1);  // Process with ID 2, arrival time 1, burst time 8, priority 1
    
    Process p3(3, 1, 1, 2);

    mlq.enqueueProcess(p1);
    mlq.enqueueProcess(p2);
    
    mlq.enqueueProcess(p3);

    // Simulate CPU scheduling
    mlq.simulateScheduling();

    return 0;
}