#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
int sum;
void *sumf(void *input);
int main(int argc,char *argv[])
{
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid,&attr,sumf,argv[1]);
    pthread_join(tid,NULL);
    printf("Sum =%d\n",sum);
    return 0;
}

void *sumf(void *input)
{
    int n=atoi(input);
    sum=0;
    int i;
    for(i=0;i<n;i++)
    {sum+=i;}

    pthread_exit(0);
}
