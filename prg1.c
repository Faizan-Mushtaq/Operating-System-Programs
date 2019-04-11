#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int x,y;
    x=fork();
    if(x==0)
    {
        printf("This is child process Id=%d\nIts parent Id=%d\n",getpid(),getppid());
        execl("add","add","10","20",(char*)NULL);
        exit (0);
    }
    else
    {
        wait();
        printf("This is parent process Id=%d\nIts parent Id=%d\n",getpid(),getppid());
        exit(0);
    }
    return 0;
}
