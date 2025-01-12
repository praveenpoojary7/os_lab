//requires edit

#include<stdio.h>
typedef struct{
    int processId;
    int burstTime;
    int priority;
    int arriveTime;
}Process;
void fcfs(Process processes[],int n)
{
    int waitingTime =0;
    int time=0;
    float totalWaitingTime=0;
    float averageWaitingTime;
    printf("\nFCFS Scheduling Algorithm:\n");
    for(int i=0;i<n;i++)
    {
        if(processes[i].arriveTime>time)
        {
            time=processes[i].arriveTime;
        }
        
        /*printf("Process %d is running.\n",processes[i].processId);
        waitingTime+=processes[i].burstTime;
        printf("Process %d finished. waiting time...%dms\n",processes[i].processId,waitingTime);
        totalWaitingTime+=waitingTime;*/
    }
    averageWaitingTime=totalWaitingTime/n;
    printf("Average Waiting Time: %.2fms\n",averageWaitingTime);
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
        printf("Process %d finished. Waiting time: %dms\n",processes[i].processId,waitingTime);
        totalWaitingTime+=waitingTime;
    }
    averageWaitingTime=totalWaitingTime/n;
    printf("Average Waiting Time: %.2fms\n",averageWaitingTime);
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
        printf("Process %d finished. Waiting time: %dms\n",processes[i].processId,waitingTime);
        totalWaitingTime+=waitingTime;
    }
    averageWaitingTime=totalWaitingTime/n;
    printf("Average Waiting Time: %.2fms\n",averageWaitingTime);
}
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    Process processes[n];
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the details for processes %d:\n",i+1);
        processes[i].processId=i+1;
        printf("Enter the burst time(ms): ");
        scanf("%d",&processes[i].burstTime);
        printf("Enter the priority: ");
        scanf("%d",&processes[i].priority);
        printf("Enter the Arrival times: ");
        scanf("%d",&processes[i].arriveTime);
    }
    fcfs(processes,n);
    SJN(processes,n);
    priorityScheduling(processes,n);
    return 0;
}