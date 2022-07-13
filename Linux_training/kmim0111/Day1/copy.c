#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    int c;
    char buffer[1024];
    int in,out;
    int nread;

    in = open("file.in",O_RDONLY);
    out = open("file.out",O_WRONLY);
    if(in<0)
     {
      perror("File Faile\n");
      printf("errno=%d\n",errno);
     }

    while((nread= read(in,buffer,sizeof(buffer)))>0)
        write(out,buffer,nread);

    exit(0);
}
