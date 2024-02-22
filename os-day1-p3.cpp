#include <stdio.h>

// Structure to represent a process
struct Process {
    int process_id;     // Process ID
    int arrival_time;   // Arrival time
    int burst_time;     // Burst time
};

// Function to execute processes using FCFS scheduling
void executeFCFS(struct Process processes[], int n) {
    int total_waiting_time = 0;  // Total waiting time
    int total_turnaround_time = 0;  // Total turnaround time

    int current_time = 0;  // Current time

    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        // Calculate waiting time for the current process
        int waiting_time = current_time - processes[i].arrival_time;

        if (waiting_time < 0) {
            // The process has not arrived yet, so the waiting time is 0.
            waiting_time = 0;
        }

        // Calculate turnaround time for the current process
        int turnaround_time = waiting_time + processes[i].burst_time;

        // Update total waiting and turnaround times
        total_waiting_time += waiting_time;
        total_turnaround_time += turnaround_time;

        // Print process details
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, waiting_time, turnaround_time);

        // Move the current time forward
        current_time += processes[i].burst_time;
    }

    // Calculate and print average waiting and turnaround times
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int n;  // Number of processes

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];  // Array to store processes

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        processes[i].arrival_time = 0;  // All processes are activated at time 0.
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    // Execute processes using FCFS scheduling
    executeFCFS(processes, n);

    return 0;
}
