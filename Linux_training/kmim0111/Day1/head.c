#include <stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char const *argv[])
{
	int fd , ret ;
	int count =0;
	char buff[200];
	int temp =0 ;

	fd = open(argv[1],O_RDONLY);
	if(fd < 0)
	{
			perror("Open Failed!!!");
			exit(0);
	}
	
	ret = read(fd,buff,sizeof(buff));
	if(ret < 0)
	{
		perror("Read Failed!!!");
		exit(0);
	}

	for(int i =0 ; i < ret ;i++)
	{
		if(buff[i] == '\n')
		{
			count++;
			if(count == 10)
			{
				write(1,buff,i+1);
				exit(0);
			}
		}
	}

	return 0;
}
