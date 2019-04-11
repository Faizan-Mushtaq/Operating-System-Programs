#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    int pageno,address,offset;
    address=atoi(argv[1]);
    pageno=address>>12;
    offset=address & 0xFFF;
    printf("Page no=%d\nOffset=%d\n",pageno,offset);
    return 0;
}
