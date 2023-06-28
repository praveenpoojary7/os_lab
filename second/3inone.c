#include<stdio.h>
void printer(int processes[],int n,int burst_time[],int arrival_time[])
{
    int WT[n],TAT[n],total_WT=0,total_TAT=0,completion_time[n];
    for (int i = 0; i < n; i++)//calculating times
    {
        if(i==0)
        {
            WT[0]=0;
            completion_time[0]=burst_time[0]+arrival_time[0];
            TAT[0]=completion_time[0]-arrival_time[0];
            total_TAT=TAT[0];
            continue;
        }
        if(completion_time[i-1]<arrival_time[i])
        {
            completion_time[i]=arrival_time[i]+burst_time[i];
        }
        else
        {
            completion_time[i]=completion_time[i-1]+burst_time[i];
        }
        TAT[i]=completion_time[i]-arrival_time[i];
        total_TAT+=TAT[i];
        WT[i]=TAT[i]-burst_time[i];
        total_WT+=WT[i];
    }
    printf("Processes\tAT\tBT\tWT\tTAT\tCT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\n",processes[i],arrival_time[i],burst_time[i],WT[i],TAT[i],completion_time[i]);
    }
    printf("AVG waiting time: %2f\n",(float)total_WT/n);
    printf("AVG turnaround time: %2f\n",(float)total_TAT/n);
    printf("\n");
}
void fcfs(int processes[],int n,int burst_time[],int arrival_time[])
{
    for (int i = 0; i < n; i++)//sorting in fcfs
    {
        int first=i;
        for (int j = i+1; j < n; j++)
        {
            if (arrival_time[j]<arrival_time[first])
            {
                first=j;
            }
        }
        int temp=arrival_time[i];
        arrival_time[i]=arrival_time[first];
        arrival_time[first]=temp;
        
        temp=processes[i];
        processes[i]=processes[first];
        processes[first]=temp;

        temp=burst_time[i];
        burst_time[i]=burst_time[first];
        burst_time[first]=temp;
    }
    printf("FCFS agorithm\n");
    printer(processes,n,burst_time,arrival_time);
}
void sjf(int processes[],int n,int burst_time[],int arrival_time[])
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

        temp=arrival_time[i];
        arrival_time[i]=arrival_time[shortest_job_index];
        arrival_time[shortest_job_index]=temp;
    }
    printf("SJF agorithm\n");
    printer(processes,n,burst_time,arrival_time);
}
void priority(int processes[],int n,int burst_time[],int arrival_time[],int priority[])
{
    int WT[n],TAT[n],total_WT=0,total_TAT=0,completion_time[n];
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
    for (int i = 0; i < n; i++)//calculating times
    {
        if(i==0)
        {
            WT[0]=0;
            completion_time[0]=burst_time[0]+arrival_time[0];
            TAT[0]=completion_time[0]-arrival_time[0];
            total_TAT=TAT[0];
            continue;
        }
        if(completion_time[i-1]<arrival_time[i])
        {
            completion_time[i]=arrival_time[i]+burst_time[i];
        }
        else
        {
            completion_time[i]=completion_time[i-1]+burst_time[i];
        }
        TAT[i]=completion_time[i]-arrival_time[i];
        total_TAT+=TAT[i];
        WT[i]=TAT[i]-burst_time[i];
        total_WT+=WT[i];
    }
    printf("Priority algorithm\n");
    printf("Processes\tAT\tBT\tPriority\tWT\tTAT\tCT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t%d\t%d\t\t%d\t%d\t%d\n",processes[i],arrival_time[i],burst_time[i],priority[i],WT[i],TAT[i],completion_time[i]);
    }
    printf("AVG waiting time: %2f\n",(float)total_WT/n);
    printf("AVG turnaround time: %2f\n",(float)total_TAT/n);
    printf("\n");
}
void roundRobin(int processes[],int n,int burst_time[],int quantum,int arrival_time[],int priority[])
{
    int remaining_time[n],WT[n],TAT[n],total_WT=0,total_TAT=0,time=0,RT[n],flag[n],avg_RT=0;
    int completion_time[n];
    int all_processes_completed[n];
    for (int i = 0; i < n; i++)//sorting in fcfs
    {
        int first=i;
        for (int j = i+1; j < n; j++)
        {
            if (priority[j]>priority[first])
            {
                first=j;
            }
        }
        int temp=arrival_time[i];
        arrival_time[i]=arrival_time[first];
        arrival_time[first]=temp;

        temp=priority[i];
        priority[i]=priority[first];
        priority[first]=temp;
        
        temp=processes[i];
        processes[i]=processes[first];
        processes[first]=temp;

        temp=burst_time[i];
        burst_time[i]=burst_time[first];
        burst_time[first]=temp;
    }
    for (int i = 0; i < n; i++)//setting remaining time
    {
        remaining_time[i]=burst_time[i];
        RT[i]=0;
        flag[i]=0;
        completion_time[n]=0;
        all_processes_completed[i]=1;
    }
    //round robin process
    int check=0;
    while(check!=0)
    {
        int x=time;
        for (int i = 0; i < n; i++)
        {
            if (remaining_time[i]>0&&arrival_time[i]<=time)//if time remaining and process entered before or at time
            {
                if(flag[i]==0){
                    flag[i]=1;
                    RT[i]=time-arrival_time[i];
                    avg_RT+=RT[i];
                    printf("FLAG SET\n");
                }
                printf("TEST");
                if (remaining_time[i]>quantum)
                {
                    remaining_time[i]-=quantum;
                    time+=quantum;
                    printf("i value:%d\tremain time:%d\ttime:%d\n",i,remaining_time[i],time);
                }
                else
                {
                    time+=remaining_time[i];
                    completion_time[i]=time;
                    WT[i]=completion_time[i]-arrival_time[i];
                    remaining_time[i]=0;
                    all_processes_completed[i]=0;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            check+=all_processes_completed[i];
        }
        if (time==x&&check!=0)
        {
            time++;
        }
    }
    for (int i = 0; i < n; i++)//calculating times
    {
        if(i==0)
        {
            WT[0]=0;
            completion_time[0]=burst_time[0]+arrival_time[0];
            TAT[0]=completion_time[0]-arrival_time[0];
            total_TAT=TAT[0];
            continue;
        }
        if(completion_time[i-1]<arrival_time[i])
        {
            completion_time[i]=arrival_time[i]+burst_time[i];
        }
        else
        {
            completion_time[i]=completion_time[i-1]+burst_time[i];
        }
        TAT[i]=completion_time[i]-arrival_time[i];
        total_TAT+=TAT[i];
        WT[i]=TAT[i]-burst_time[i];
        total_WT+=WT[i];
    }
    printf("ROund RObin algorithm\n");
    printf("Processes\tAT\tBT\tPriority\tWT\tTAT\tCT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t%d\t%d\t\t%d\t%d\t%d\t%d\n",processes[i],arrival_time[i],burst_time[i],priority[i],WT[i],TAT[i],completion_time[i],RT[i]);
    }
    printf("AVG waiting time: %2f\n",(float)total_WT/n);
    printf("AVG turnaround time: %2f\n",(float)total_TAT/n);
    printf("AVG Response time: %2f\n",(float)avg_RT/n);
    printf("\n");
}
void main()
{
    int n=4;
    int quantum;
    //printf("Enter the number of processes: ");
    //scanf("%d",&n);
    //int processes[n],burst_time[n],arrival_time[n],prioritylist[n];
    /*for (int i = 0; i < n; i++)
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
    scanf("%d",&quantum);*/
    int processes[4]= {1,2,3,4};
    int burst_time[4]= {5,4,3,2};
    int arrival_time[4]= {2,3,4,5};
    int prioritylist[4]= {1,1,1,1};
    quantum=3;
    //fcfs(processes,n,burst_time,arrival_time);
    //priority(processes,n,burst_time,arrival_time,prioritylist);
    roundRobin(processes,n,burst_time,quantum,arrival_time,prioritylist);
    //sjf(processes,n,burst_time,arrival_time);
}