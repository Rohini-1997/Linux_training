#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
int main()
{
    char buffer;
    int in;
    int nread;

    in = open("file.in",O_RDONLY);
    if(in<0)
    {
     perror("Faile fail\n");
     printf("errno=%d\n",errno);
    }
    read(in,&buffer,1);
    printf("%c",buffer);


    exit(0);
}

