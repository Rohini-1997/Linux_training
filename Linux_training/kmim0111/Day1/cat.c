#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	int ret,nread;
	char buff;
	
	ret = open(argv[1],O_RDONLY);
        
	if (ret < 0)
	{
		perror("open fails:");
		printf("errno:%d\n",errno);
	}
	else
         {
		printf("open success ret:%d\n",ret);
                
         }
        while((nread= read(ret,&buff,1))>0)
        {
         write(1,&buff,nread);
//         printf("%c",buff);
        }
}
