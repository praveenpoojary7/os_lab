#include<stdio.h>
void Sorter(int priority[],int n,int processes[],int burst_time[],int arrival_time[],int key)
{
    for (int i = 0; i < n; i++)//sorting in priority
    {
        int first=i;
        for (int j = i+1; j < n; j++)
        {
            if (priority[j]>priority[first])
            {
                first=j;
            }
        }
        break;
        int temp=priority[i];
        priority[i]=priority[first];
        priority[first]=temp;
        
        temp=processes[i];
        processes[i]=processes[first];
        processes[first]=temp;

        temp=burst_time[i];
        burst_time[i]=burst_time[first];
        burst_time[first]=temp;

        temp=arrival_time[i];
        arrival_time[i]=arrival_time[first];
        arrival_time[first]=temp;
    }
}
void roundRobin(int processes[],int n,int burst_time[],int quantum,int arrival_time[],int priority[])
{
    int remaining_time[n],WT[n],TAT[n],total_WT=0,total_TAT=0,time=0,RT[n],flag[n],avg_RT=0;
    int completion_time[n];
    int all_processes_completed[n],idle=0;
    Sorter(priority,n,processes,burst_time,arrival_time,3);
    for (int i = 0; i < n; i++)//setting remaining time
    {
        remaining_time[i]=burst_time[i];
        RT[i]=0;
        flag[i]=0;
        completion_time[n]=0;
        all_processes_completed[i]=1;
    }
    while(1)
    {
        int x=time,check=0;
        for (int i = 0; i < n; i++)
        {
            if (remaining_time[i]>0&&arrival_time[i]<=time)//preemption process
            {
                if(flag[i]==0){
                    flag[i]=1;
                    RT[i]=time-arrival_time[i];
                    avg_RT+=RT[i];
                }
                if (remaining_time[i]>quantum)
                {
                    remaining_time[i]-=quantum;
                    time+=quantum;
                }
                else
                {
                    time+=remaining_time[i];
                    completion_time[i]=time;
                    remaining_time[i]=0;
                    all_processes_completed[i]=0;
                }
            }
        }
        for (int i = 0; i < n; i++)//checking if all processes have finished executing
        {
            check+=all_processes_completed[i];
        }
        if (time==x&&check!=0)//checking for idle times
        {
            time++;
            idle++;
        }
        if (check==0)break;
        
    }
    for (int i = 0; i < n; i++)//calculating times
    {
        TAT[i]=completion_time[i]-arrival_time[i];
        total_TAT+=TAT[i];
        WT[i]=TAT[i]-burst_time[i];
        total_WT+=WT[i];
    }
    printf("\nROund RObin algorithm\n");
    printf("Processes\tAT\tBT\tPriority\tWT\tTAT\tCT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t%d\t%d\t\t%d\t%d\t%d\t%d\n",processes[i],arrival_time[i],burst_time[i],priority[i],WT[i],TAT[i],completion_time[i],RT[i]);
    }
    printf("AVG waiting time: %2f\n",(float)total_WT/n);
    printf("AVG turnaround time: %2f\n",(float)total_TAT/n);
    printf("AVG Response time: %2f\n",(float)avg_RT/n);
    printf("Total Idle time: %d\n",idle);
    printf("\n");
}
void main()
{
    int n;
    int quantum;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int processes[n],burst_time[n],arrival_time[n],prioritylist[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time for process %d:",i+1);
        scanf("%d",&arrival_time[i]);
        printf("Enter the Burst time for processes %d:",i+1);
        scanf("%d",&burst_time[i]);
        printf("Enter the priority for process %d:",i+1);
        scanf("%d",&prioritylist[i]);
        processes[i]=i+1;
    }
    printf("Enter the time quantum for round robin: ");
    scanf("%d",&quantum);
    roundRobin(processes,n,burst_time,quantum,arrival_time,prioritylist);
}
/* output
 Total number of processes in the system: 4

Enter the Arrival and Burst time of Process[1]
Arrival time: 0
Burst time: 5

Enter the Arrival and Burst time of Process[2]
Arrival time: 2
Burst time: 4

Enter the Arrival and Burst time of Process[3]
Arrival time: 3
Burst time: 2

Enter the Arrival and Burst time of Process[4]
Arrival time: 5
Burst time: 1
Enter the Time Quantum for the processes: 3

Process No      Burst Time      TAT     Waiting Time
Process No[3]   2               5       3
Process No[4]   1               4       3
Process No[1]   5               11      6
Process No[2]   4               10      6

Average Turn Around Time: 4.500000
Average Waiting Time: 7.500000
    /*
