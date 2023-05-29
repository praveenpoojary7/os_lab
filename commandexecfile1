#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    int status;
    pid = fork();
    if(pid<0)
    {
        printf("ERROR: fork() failed\n");
        return 1;
    }
    else if(pid==0)
    {
        printf("This is the child process with PID: %d\n",getpid());
        printf("Parent process with PID: %d\n",getppid());
        execlp("/bin/ls","ls",NULL);
        printf("This shouldn't be displayed if exec() was successful\n");
        return 0;
    }
    else
    {
        printf("This is the parent process with PID: %d\n",getpid());
        printf("Child process with PID: %d\n",pid);
        wait(&status);
        printf("Child process exited with status: %d\n",status);
        return 0;
    }
}
