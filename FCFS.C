#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int Process_ID[n];
    int Burst_Time[n];
    int Waiting_Time[n];
    int Turnaround_Time[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter Process ID for process %d: ", i + 1);
        scanf("%d", &Process_ID[i]);
        
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &Burst_Time[i]);
    }

    // Calculate Waiting Time
    Waiting_Time[0] = 0;

    for (int i = 1; i < n; i++) {
        Waiting_Time[i] = Waiting_Time[i - 1] + Burst_Time[i - 1];
    }

    // Calculate Turnaround Time
    for (int i = 0; i < n; i++) {
        Turnaround_Time[i] = Waiting_Time[i] + Burst_Time[i];
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
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n",
               Process_ID[i],
               Burst_Time[i],
               Waiting_Time[i],
               Turnaround_Time[i]);
    }

    printf("\nAverage Waiting Time = %.2f", Average_Waiting_Time);
    printf("\nAverage Turnaround Time = %.2f\n", Average_Turnaround_Time);

    return 0;
}

