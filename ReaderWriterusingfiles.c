#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<fcntl.h>
int readcount=0;
int count=0;
void *readtask();
void *writetask();
sem_t mutex,wrt;
 void main()
{
    int i=0;
    pthread_t readid[10];
    pthread_t writeid;
    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);
    for(i=0;i<5;i++)
    {
        pthread_create(&readid[i],NULL,readtask,NULL);
        if(i==2)
        pthread_create(&writeid,NULL,writetask,NULL);
    }
    for(i=0;i<5;i++)
    pthread_join(readid[i],NULL);

    pthread_join(writeid,NULL);
    sem_destroy(&mutex);
    sem_destroy(&wrt);
}
void *readtask()
{
    int fd;
    sem_wait(&mutex);
    readcount++;
    if(readcount==1)
    sem_wait(&wrt);
    char sent[100];
    fd=open("f1.txt",0);
    read(fd,sent,20);
    printf("reader %d  is reading %s\n",count++,sent);
    sem_post(&mutex);
    readcount--;
    sleep(1);
    if(readcount==0)
    sem_post(&wrt);
    sem_post(&mutex);
}
void *writetask()
{
    int fd;
    char sent[100]="RVCE";
    sem_wait(&wrt);
    fd=open("f1.txt",1);
    lseek(fd,SEEK_SET,10);
    write(fd,sent,10);
    printf("Writer is writing\n");
    close(fd);
    sem_post(&wrt);
}
