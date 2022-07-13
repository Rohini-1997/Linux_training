#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
void main(int argc,char *argv[])
{
	int fd,nread,count=0,size,line=0;
	char buffer;
	if(argc !=2)
	{
   	printf("usage:./a.out filename\n");
   	return;
	}
	fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
  	perror("File open:");
  	printf("errno=%d\n",errno);
	}
	while((nread=read(fd,&buffer,1))>0)
	{  size++;
   	if(buffer ==' ' ||buffer =='\n')
   	{
	count++;
	}
	if(buffer == '\n')
	{
	line++;
	}
	}
printf("Word count=%d line count=%d\n",count,line);
}
