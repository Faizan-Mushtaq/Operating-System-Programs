#include<stdio.h>
#include<unistd.h>
#include<sched.h>
#include<sys/types.h>
#include<sys/resource.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    pid_t pid;
    if(argc==2)
    pid=atoi(argv[1]);
    else
    pid=getpid();

    printf("Process Id =%d\n",pid);
    int c=0,i;
    for(i=-20;i<20;i+=2)
    {
        int a=getpriority(PRIO_PROCESS,pid);
        int b=setpriority(PRIO_PROCESS,pid,i);
        if(b==0)
        c=getpriority(PRIO_PROCESS,pid);
        printf("%d\t%d\t%d\n",a,b,c);
    }

    printf("policy changing program\n");
    pid_t t;
    t=getpid();
    int a=sched_getscheduler(t);
    if(a==SCHED_FIFO)
    printf("FIFO SCHEDULING\n");
    if(a==SCHED_RR)
    printf("ROUND ROBIN SCHD\n");
    if(a==SCHED_OTHER)
    printf("DEFAULT SCHEDULING\n");
    printf("policy =%d\n",a);

    struct sched_param p;
    p.sched_priority=20;
    a=SCHED_RR;
    int b=sched_setscheduler(t,a,&p);
    printf("value of b=%d\n",b);
    a=sched_getscheduler(t);
    if(a==SCHED_FIFO)
    printf("FIFIO SCHED\n");
    if(a==SCHED_RR)
    printf("RR SCHED\n");
    if(a==SCHED_OTHER)
    printf("DEFAULT SCHED\n");
    printf("Policy set to=%d\n,",a);
    return 0;
}
