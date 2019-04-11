#include <stdio.h>
#include<unistd.h>
#include <sched.h>

void main(int argc,char*argv[])
{
  int pro,res;
  printf("Enter number of processes & resources\n" );
  scanf("%d",&pro );
  scanf("%d",&res );

  int max[pro][res],alloc[pro][res],need[pro][res];
  printf("Enter max matrix\n");
  for(int i=0;i<pro;i++)
  {
    for(int j=0;j<res;j++)
    {
      scanf("%d",&max[i][j] );
    }
  }

  printf("Enter alloc matrix\n" );
  for(int i=0;i<pro;i++)
  {
    for(int j=0;j<res;j++)
    {
      scanf("%d",&alloc[i][j] );
    }
  }

  printf("Need matrix is\n" );
  for(int i=0;i<pro;i++)
  {
    for(int j=0;j<res;j++)
    {
      need[i][j]=max[i][j]-alloc[i][j];
      printf("%d ",need[i][j] );
    }printf("\n" );
  }

  printf("Enter the available resources\n" );
  int avail[res];
  for(int i=0;i<res;i++)
    scanf("%d",&avail[i]);

  //Request resource algo
  int p;
  printf("Enter process number\n" );
  scanf("%d",&p );

  printf("Enter request\n" );
  int req[res];

  for(int i=0;i<res;i++)
    scanf("%d",&req[i]);

  //if request < need && request <avail do the three
  int flag=0;
  printf("RESOURCE REQUEST\n" );
  for(int i=0;i<res;i++)
  {
    if(req[i]<=avail[i]&&req[i]<=need[p][i])
      flag=1;
    else
    {flag=0;break;}
  }
  if(flag==1)
  printf("Request can be allocated\n" );
  else
  printf("Request cannot be allocated\n" );

  for(int i=0;i<res;i++)
  {
    avail[i]-=req[i];
    alloc[p][i]+=req[i];
    need[p][i]-=req[i];
  }

  //safety algo
printf("New need matrix\n" );
  for(int i=0;i<pro;i++)
  {
    for(int j=0;j<res;j++)
    {
      //need[i][j]=max[i][j]-alloc[i][j];
      printf("%d ",need[i][j]);
    }printf("\n" );
  }

  int work[res];
  for(int i=0;i<res;i++)
  {
    work[i]=avail[i];
    printf("%d ",work[i]);
  }//copied
  int count=0;
  int finish[pro],k=0;
  for(int i=0;i<pro;i++)
    finish[i]=0;
  int order[pro];
  for(int i=0;i<pro;i=(i+1)%pro)
  {
    if(count>pro*pro)
    break;
    count++;
    flag=0;
    if(finish[i]==0)
    {//unfinished
      printf("Process %d\n",i );
    for(int j=0;j<res;j++)
    {
      if(work[j]>=need[i][j])
       flag=1;
       else{
       flag=0;
       break;}
    }
    if(flag==1)//applicable for all resources
    {
      printf("applicable\n" );
      for(int j=0;j<res;j++)
      {
        work[j]+=alloc[i][j];
      }finish[i]=1;
      order[k++]=i;
      printf("available\n" );
      for(int x=0;x<res;x++)
      printf("%d ",work[x] );
      printf("\n" );
    }
    }
    //check if all done
    printf("k=%d\n",k );
    if(k==pro)
    {
      printf("All processes accepted\n" );
      //all done
      break;
    }
  }

printf("The order is\n" );
  for(int i=0;i<k;i++)
  {
    printf("%d\n",order[i] );
  }





}
