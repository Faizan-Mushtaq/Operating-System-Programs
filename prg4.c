#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>
#include<sys/resource.h>
#include<sys/types.h>
#include<pthread.h>
int count=1;
enum {TH, HU, EA} state[5];
int ph[5] = {0,1,2,3,4};
sem_t s[5];
sem_t mutex;

void test(int i)
{
  int l,r,x;
  l = (i+4)%5;
  r = (i+1)%5;
  while(state[i] == HU && state[l] != EA && state[r] != EA)
  {
    state[i] = EA;
    printf("\nPhil %d is eating with %d and %d", i,l,r);
    sleep(2);
    //sem_post(&s[i]);
  }
}

void pickup(int i)
{
  sem_wait(&mutex);
  state[i] = HU;
  printf("\nPhil %d is hungzz", i);
  test(i);
  sem_post(&mutex);
//  sem_wait(&s[i]);
  sleep(1);
}

void putdown(int i)
{
  int l,r,x;
  l = (i+4)%5;
  r = (i+1)%5;
  sem_wait(&mutex);
  state[i] = TH;
  printf("\nPhil %d is thinkzzz ", i);
  test(l);
  test(r);
  sem_post(&mutex);
}

void *runner(void * i)
{
  int x =count++;
  printf("x=%d\n",x );
    pickup(x);
    sleep(2);
    putdown(x);

}
int main()
{
  int i,j;
  pthread_t p[5];

  sem_init(&mutex, 0,1);
  for(i=0;i<5;i++)
    sem_init(&s[i], 0 ,0);
  for(i=0;i<5;i++)
  {
    pthread_create(&p[i], NULL, runner,&i);
  }
  for(i=0;i<5;i++)
  {
    pthread_join(p[i],NULL);
  }
  return 0;
}
