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
    int remaining_time[n],WT[n],TAT[n],total_WT=0,total_TAT=0;
    for (int i = 0; i < n; i++)
    {
        remaining_time[i]=burst_time[i];
    }
    int time=0;
    while(1)
    {
        int all_processes_completed=1;
        for (int i = 0; i < n; i++)
        {
            if (remaining_time[i]>0)
            {
                all_processes_completed=0;
                if (remaining_time[i]>quantum)
                {
                    time+=quantum;
                    remaining_time[i]-=quantum;
                }
                else
                {
                    time+=remaining_time[i];
                    WT[i]=time-burst_time[i];
                    remaining_time[i]=0;
                }
            }
        }
        if (all_processes_completed)
        {
            break;
        }
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
    printf("Round Robin algorithm\n");
    printf("Processes\tBurst Time\tWaiting TIme\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n",processes[i],burst_time[i],WT[i],TAT[i]);
    }
    printf("AVG waiting time: %2f\n",(float)total_WT/n);
    printf("AVG turnaround time: %2f\n",(float)total_TAT/n);
    printf("\n");
}
void main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int processes[n],burst_time[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Burst time for processes %d",processes[i]+1);
        scanf("%d",&burst_time[i]);
        processes[i]=i+1;
    }
    printf("Enter the time quantum for round robin: ");
    int quantum;
    scanf("%d",&quantum);
    fcfs(processes[n],n,burst_time[n]);
    sjf(processes[n],n,burst_time[n]);
    roundRobin(processes[n],n,burst_time[n],quantum);
}