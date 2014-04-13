/* Rewrite the program cat from Chapter 7 using read,write,open and close
instead of their standard library equivalents. Perform experiments to determine
the relative speeds of the two versions */ 
#include<stdio.h> #include<fcntl.h>

void error(char *fmt,...);

/* cat: concatenate files - read/write/open/close */

int main(int argc,char *argv[])
{
	int fd;
	void filecopy(int ifd,int ofd);
	
	if(argc == 1)
		filecopy(0,1);
	else
		while(--argc > 0)
			if((fd = open(*++argv,O_RDONLY)) == -1)
				error("cat:can't open %s",*argv);
			else
			{
				filecopy(fd,1);
				close(fd);
			}
	return 0;
}

/* filecopy: copy file ifd to ofd */
void filecopy(int ifd,int ofd)
{
	int n;
	char buf[BUFSIZ];
	
	while((n=read(ifd,buf,BUFSIZ)) > 0)
		if(write(ofd,buf,n) != n)
			error("cat:write error");
}


#include<stdarg.h>
/* error: print an error message and die */
void error(char *fmt,...)
{
	va_list args;
	
	va_start(args,fmt);
	fprintf(stderr,"error: ");
	vfprintf(stderr,fmt,args);
	fprintf(stderr,"\n");
	va_end(args);
	
	exit(1);
}

