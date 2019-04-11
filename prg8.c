#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int size,h=0,i=0,a[20],b[20],original_size,max_size;
void allocate()
{
    int req,t,u,z=0;
    int actual=original_size;
    if(size<=0)
    {
        printf("No space available\n");
        return;
    }
    printf("Enter the required allocation size\n");
    scanf("%d",&req);
    if(req<=max_size)
    {
        int small;
        int valid=0;
        z=0;
        while((t=actual/pow(2,z))>=req)
        {
            u=t;
            z+=1;
        }
        printf("%d is the size required\n",u);
        size-=u;
        a[++i]=u;
        b[++h]=req;
        printf("Remaining memory=%d\n",size);
    }
    else
    {
        printf("Cannot allocate memory\n");
        exit(0);
    }
    printf("Required \t\tAllocation\n");
    for(int k=1;k<=i;k++)
    printf("%d\t\t%d\n",b[k],a[k]);
}
void deallocate(int n)
{
    if(i==0)
    {
        printf("Memory not yet allocated \n");
        return;
    }
    int flag=0;
    for (int j=0;j<=i;j++)
    {
        if(a[j]==n)
        {
            flag=1;
            for(int k=j;k<i;k++)
            {
                a[k]=a[k+1];
                b[k]=b[k+1];
            }
            size+=n;
            break;
        }
    }
    printf("Remaining memory = %d\n",size);
    if(flag==0)
    printf("Not found in memory\n");
}
int main()
{
    printf("Enter memory size\n");
    scanf("%d",&size);
    original_size=size;
    max_size=size;
    int mem,ch;
    while(1)
    {
        printf("Enter 1.Allocate 2.Deallocate\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:allocate();
                    break;
            case 2:printf("Enter mem size to deallocate\n");
                    scanf("%d",&mem);
                    deallocate(mem);
                    break;
        }
    }
    return 0;
}
