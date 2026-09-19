//shortest job first
#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int Process_ID[n];
    int Burst_Time[n];
    int Arrival_Time[n];
    int Completion_Time[n];
    int Waiting_Time[n];
    int Turnaround_Time[n];
    int Completed[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter Process ID for process %d: ", i + 1);
        scanf("%d", &Process_ID[i]);

        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &Burst_Time[i]);

        printf("Enter Arrival Time for process %d: ", i + 1);
        scanf("%d", &Arrival_Time[i]);

        Completed[i] = 0;
    }

    int Current_Time = 0;
    int Completed_Count = 0;

    // Calculate Completion, Waiting and Turnaround Time
    while (Completed_Count < n) {
        int Shortest_Burst = 9999;
        int Selected_Process = -1;

        // Find process with shortest burst time
        for (int i = 0; i < n; i++) {
            if (Completed[i] == 0 &&
                Arrival_Time[i] <= Current_Time) {

                if (Burst_Time[i] < Shortest_Burst) {
                    Shortest_Burst = Burst_Time[i];
                    Selected_Process = i;
                }
            }
        }

        // If no process is available
        if (Selected_Process == -1) {
            Current_Time++;
        }
        else {
            Completion_Time[Selected_Process] =
                Current_Time + Burst_Time[Selected_Process];

            Turnaround_Time[Selected_Process] =
                Completion_Time[Selected_Process]
                - Arrival_Time[Selected_Process];

            Waiting_Time[Selected_Process] =
                Turnaround_Time[Selected_Process]
                - Burst_Time[Selected_Process];

            Current_Time =
                Completion_Time[Selected_Process];

            Completed[Selected_Process] = 1;
            Completed_Count++;
        }
    }

    // Calculate averages
    float Average_Waiting_Time = 0;
    float Average_Turnaround_Time = 0;

    for (int i = 0; i < n; i++) {
        Average_Waiting_Time += Waiting_Time[i];
        Average_Turnaround_Time += Turnaround_Time[i];
    }

    Average_Waiting_Time /= n;
    Average_Turnaround_Time /= n;

    // Display results
    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               Process_ID[i],
               Arrival_Time[i],
               Burst_Time[i],
               Completion_Time[i],
               Waiting_Time[i],
               Turnaround_Time[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
           Average_Waiting_Time);

    printf("\nAverage Turnaround Time = %.2f\n",
           Average_Turnaround_Time);

    return 0;
}
