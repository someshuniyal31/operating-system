#include <stdio.h>

struct Process {
    int pid;          
    int arrivalTime; 
    int burstTime;    
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

   
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf(" %d: ", p[i].pid);
        scanf("%d%d", &p[i].arrivalTime, &p[i].burstTime);
    }

   
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(p[j].arrivalTime > p[j+1].arrivalTime) {
                struct Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

   
    int currentTime = 0;
    for(int i = 0; i < n; i++) {
        if(currentTime < p[i].arrivalTime) {
            currentTime = p[i].arrivalTime;
        }
        p[i].completionTime = currentTime + p[i].burstTime;
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;
        currentTime = p[i].completionTime;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime,
               p[i].completionTime, p[i].turnaroundTime, p[i].waitingTime);
    }

    return 0;
}
