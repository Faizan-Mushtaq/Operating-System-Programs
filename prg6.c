#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
int buffer[5],front,rear;
sem_t mutex,full,empty;

void *producer(void *arg)
{
    int i;
    for(i=0;i<=5;i++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("Produced item is %d \n",i);
        buffer[(++rear)%5]=i;
        sleep(1);
        sem_post(&mutex);
        sem_post(&full);
    //    printf("Full %u \n",full);
    }
}
void *consumer(void *arg)
{
    int item,i;
    for(i=0;i<=5;i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        item=buffer[(++front)%5];
        printf("Consumed item is %d\n",item);
        sleep(1);
        sem_post(&mutex);
        sem_post(&empty);
    }
}
int main()
{
    pthread_t tid1,tid2;
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,5);
    pthread_create(&tid1,NULL,producer,NULL);
    pthread_create(&tid2,NULL,consumer,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    return 0;
}
