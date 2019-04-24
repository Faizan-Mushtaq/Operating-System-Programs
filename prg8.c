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
        //int small;
        //int valid=0;
        z=0;
        while((t=actual/pow(2,z))>=req)
        {
            u=t;
            z+=1;
        }
        //printf("%d is the size required\n",u);
        size-=u;

        if(size<0)
        {
        printf("memory cannot be allocated\n");
        size+=u;
        return;
        }
        a[i++]=u;
        b[h++]=req;
        //printf("Remaining memory=%d\n",size);
        while((size/pow(2,z))>=1)
        z=z+1;

        max_size=pow(2,z-1);
    }
    else
    {
        printf("Cannot allocate memory\n");
        return;//exit(0);
    }

}
void deallocate(int n)
{
    int flag=0,z=0;
    if(i==0)
    {
        printf("Memory not yet allocated \n");
        return;
    }
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
            while((size/pow(2,z))>=1)
            z=z+1;

            max_size=pow(2,z-1);
            break;
        }
    }
    //printf("Remaining memory = %d\n",size);
    if(flag==0){
    printf("Not found in memory\n");
    return;
}
}
int main()
{
    printf("Enter memory size\n");
    scanf("%d",&size);
    original_size=size;
    max_size=size;
    int mem,ch,k;
    while(1)
    {
        printf("Enter 1.Allocate 2.Deallocate\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:allocate();
                    break;
            case 2: if(max_size==size)
                    {printf("not allocated\n");
                    break;}
                    printf("Enter mem size to deallocate\n");
                    scanf("%d",&mem);
                    deallocate(mem);
                    break;
        }
        printf("Required \t\tAllocation\n");
        for(int k=0;k<=i;k++)
        {
            if(a[k]!=0 && b[k]!=0)
            printf("%d\t\t%d\n",b[k],a[k]);
        }
    }
    return 0;
}
