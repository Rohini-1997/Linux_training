//My own version of System library
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
int main(int argc,char *argv[])
{
 mysystem(argv[1]);
 return 0;
}
void mysystem(char *p)
{
int ret,status;
if (fork()== 0)
{
	printf("children\n");
	ret=execl("/bin/sh", "sh", "-c",p, (char *) NULL);
        if(ret == -1)
	perror("execve fails");
	exit(0);
}
else
{
	printf("parent\n");
	wait(&status);
}

}

