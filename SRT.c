#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
};

void preemptive_sjf_scheduling(struct Process processes[], int n) {
    int completed = 0, current_time = 0;
    
    while (completed != n) {
        int shortest_time = -1;
        int current_pid = -1;
        
        // Find the process with the shortest remaining time at the current time
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (shortest_time == -1 || processes[i].remaining_time < shortest_time) {
                    shortest_time = processes[i].remaining_time;
                    current_pid = i;
                }
            }
        }
        
        if (current_pid == -1) {
            current_time++;
            continue;
        }
        
        // Execute the process for one unit of time
        processes[current_pid].remaining_time--;
        current_time++;
        
        // Check if the process is completed
        if (processes[current_pid].remaining_time == 0) {
            completed++;
            printf("Process %d completed at time %d.\n", processes[current_pid].pid, current_time);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }
    
    preemptive_sjf_scheduling(processes, n);
    
    return 0;
}
