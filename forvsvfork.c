#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main()
{
    pid_t pid;
    pid = vfork();
    if(pid==-1)
    {
        perror("vfork");
        return 1;
    }
    else if(pid==0)
    {
        printf("This is the child process with PID: %d\n",getpid());
        printf("Parent process with PID: %d\n",getppid());
        _exit(0);
    }
    else
    {
        printf("This is the parent process with PID: %d\n",getpid());
        printf("Child process with PID: %d\n",pid);
    }
    int status;
    waitpid(pid,&status,0);
    if(WIFEXITED(status))
    {
        printf("Parent process: CHild process terminated normlly.\n");
    }
    else
    {
        printf("Parent process: CHild process terminated abnormlly.\n");
    }
}
