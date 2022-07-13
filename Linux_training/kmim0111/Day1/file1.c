#include<fcntl.h> 
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc,char*argv[])
{
if(argc!=2)
{ 
printf("./a.out filename\n");
exit(1);
}
int ret,count;
char buffer[10];
ret=open(argv[1], O_RDONLY);
if(ret<-1)
{
printf("cannot open file");
exit(1);
}
while((count=read(ret,buffer,sizeof(buffer)))>0) 
{
printf("%s",buffer);
}
exit(0);
}


