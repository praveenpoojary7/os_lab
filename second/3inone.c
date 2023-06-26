#include<stdio.h>
void fcfs(int processes[],int n,int burst_time[])
{
    int WT[n],TAT[n],total_WT=0,total_TAT=0;
    WT[0]=0;
    for (int i = 1; i < n; i++)
    {
        WT[i]=burst_time[i-1]+WT[i-1];
        total_WT+=WT[i];
    }
    for (int i = 0; i < n; i++)
    {
        TAT[i]=burst_time[i]+WT[i];
        total_TAT+=TAT[i];
    }
    printf("FCFS algorithm\n");
    printf("Processes\tBurst Time\tWaiting TIme\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n",processes[i],burst_time[i],WT[i],TAT[i]);
    }
    printf("AVG waiting time: %2f\n",(float)total_WT/n);
    printf("AVG turnaround time: %2f\n",(float)total_TAT/n);
    printf("\n");
}
void sjf(int processes[],int n,int burst_time[])
{
    int WT[n],TAT[n],total_WT=0,completion_time[n],total_TAT=0;
    for (int i = 0; i < n; i++)
    {
        int shortest_job_index=i;
        for (int j = i+1; j < n; j++)
        {
            if (burst_time[j]<burst_time[shortest_job_index])
            {
                shortest_job_index=j;
            }
        }
        int temp=burst_time[i];
        burst_time[i]=burst_time[shortest_job_index];
        burst_time[shortest_job_index]=temp;
        
        temp=processes[i];
        processes[i]=processes[shortest_job_index];
        processes[shortest_job_index]=temp;
    }
    WT[0]=0;
    for (int i = 1; i < n; i++)
    {
        WT[i]=burst_time[i-1]+WT[i-1];
        total_WT+=WT[i];
    }
    for (int i = 0; i < n; i++)
    {
        TAT[i]=burst_time[i]+WT[i];
        total_TAT+=TAT[i];
    }
    printf("SJF algorithm\n");
    printf("Processes\tBurst Time\tWaiting TIme\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n",processes[i],burst_time[i],WT[i],TAT[i]);
    }
    printf("AVG waiting time: %2f\n",(float)total_WT/n);
    printf("AVG turnaround time: %2f\n",(float)total_TAT/n);
    printf("\n");
}
void roundRobin(int processes[],int n,int burst_time[],int quantum)
{
    
}