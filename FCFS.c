

#include <stdio.h>

void main() {
    int n, bt[30], wait_t[30], turn_ar_t[30];
    float av_wt_t = 0, avturn_ar_t = 0;
    int i, j;

    printf("Enter total number of processes (max 30): ");
    scanf("%d", &n);

    printf("\nEnter Process Burst Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wait_t[0] = 0; 

    
    for (i = 1; i < n; i++) {
        wait_t[i] = 0;
        for (j = 0; j < i; j++)
            wait_t[i] += bt[j];
    }

   
    for (i = 0; i < n; i++) {
        turn_ar_t[i] = bt[i] + wait_t[i];
        av_wt_t += wait_t[i];
        avturn_ar_t += turn_ar_t[i];
    }

    av_wt_t /= n;
    avturn_ar_t /= n;

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, bt[i], wait_t[i], turn_ar_t[i]);
    }

    printf("\n\nAverage Waiting Time: %.2f", av_wt_t);
    printf("\nAverage Turnaround Time: %.2f\n", avturn_ar_t);
}
