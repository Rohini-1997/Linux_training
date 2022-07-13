#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<errno.h>
#include<stdlib.h>
int main(int argc ,char *argv[])
{
	if(argc < 2)
	{
		printf("./a.out argument\n");
		return 0;
	}
	int i,count=0;
	for(i=0;argv[1][i];i++)
	{
		count++;
	}
	for(i=1;i<argc;i++)
	write(1,argv[i],count);

} 	
