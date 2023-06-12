#include<stdio.h>
typedef struct{
    int processId;
    int burstTime;
    int priority;
}Process;
void fcfs(Process processes[],int n)
{
    int waitingTime =0;
    float totalWaitingTime=0;
    float averageWaitingTime;
    printf("\nFCFS Scheduling Algorithm:\n");
    for(int i=0;i<n;i++)
    {
        printf("Process %d is running.\n",processes[i].processId);
        waitingTime+=processes[i].burstTime;
        printf("Process %d finished. waiting time...%d\n",processes[i].processId,waitingTime);
        totalWaitingTime+=waitingTime;
    }
    averageWaitingTime=totalWaitingTime/n;
    printf("Average Waiting Time: %.2f\n",averageWaitingTime);
}
void SJN(Process processes[],int n)
{
    int totalTime=0;
    int waitingTime=0;
    float totalWaitingTime=0;
    float averageWaitingTime;
    printf("\nSJN Scheduling Algorithm:\n");
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(processes[j].burstTime>processes[j+1].burstTime)
            {
                Process temp=processes[j];
                processes[j]=processes[j+1];
                processes[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("Process %d is running.\n",processes[i].processId);
        waitingTime+=totalTime;
        totalTime+=processes[i].burstTime;
        printf("Process %d finished. Waiting time: %d\n",processes[i].processId,waitingTime);
        totalWaitingTime+=waitingTime;
    }
    averageWaitingTime=totalWaitingTime/n;
    printf("Average Waiting Time: %.2f\n",averageWaitingTime);
}
void priorityScheduling(Process processes[], int n)
{
    int waitingTime=0;
    float totalWaitingTime=0;
    float averageWaitingTime;
    printf("\nPriority Scheduling Algorithm:\n");
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(processes[j].priority>processes[j+1].priority)
            {
                Process temp=processes[j];
                processes[j]=processes[j+1];
                processes[j+1]=temp;
            }
        }
        
    }
    for(int i=0;i<n;i++)
    {
        printf("Process %d is running.\n",processes[i].processId);
        waitingTime+=processes[i].burstTime;
        printf("Process %d finished. Waiting time: %d\n",processes[i].processId,waitingTime);
        totalWaitingTime+=waitingTime;
    }
    averageWaitingTime=totalWaitingTime/n;
    printf("Average Waiting Time: %.2f\n",averageWaitingTime);
}