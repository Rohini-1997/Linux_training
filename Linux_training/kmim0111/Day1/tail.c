#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	int in,nread,out,line=0;
	char buff[20];
	int count=0;
	in=open(argv[1],O_RDONLY);
	while((nread=read(in,buff,1))>0)
	{
		if (*buff=='\n')
			line++;					
	}
	printf("\n%d\n",line);
	lseek(in,0,SEEK_SET);						
	line=line-10;							
	if (line>0)
	{
		while((nread=read(in,buff,1))>0)
		{
			if(count>=line)				
				write(1,buff,nread);
			if(*buff == '\n')
				count++; 
		}
	}
	else								
	{
		while((nread=read(in,buff,1))>0)
			write(1,buff,nread);
	}
	close(in);
}	
