#include<stdio.h>
#include<unistd.h>
int main()
{
    int loc = 6;
    int pid = fork();
    if(pid==0)
    {
        printf("Child proces pid = %d\n",getpid());
        printf("Parent process pid = %d\n",getppid());
        loc++;
    }
    else
    {
        sleep(2);
        printf("parent process pid = %d\n",getpid());
        printf("Its parent process pid = %d\n",getppid());
    }
    printf("loc = %d\n",loc);
    _exit(2);
}