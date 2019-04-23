#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#define size 100
int main(int argc,char *argv[])
{
    char buf[size];
    int fd1,fd2,r,ch;
    printf("1 copy 2 move 3 remove\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
                fd1=open(argv[1],O_RDONLY,0777);
                fd2=open(argv[2],O_CREAT|O_WRONLY,0777);
                while((r=read(fd1,buf,size))>0)
                {
                    write(fd2,buf,r);
                }
                close(fd1);
                close(fd2);
                printf("File copied\n");
                break;
        case 2://second file should not be created before  
                link(argv[1],argv[2]);
                unlink(argv[1]);
                printf("File 1 moved to 2\n");
                break;
        case 3:
                unlink(argv[1]);
                printf("File 1 deleted");
                break;
    }
    return 0;
}
