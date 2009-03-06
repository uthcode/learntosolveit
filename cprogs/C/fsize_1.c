/*Modify the fsize program to print the other information contained in the inode entry */

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include"dirent.h"

int stat(char *,struct stat *);
void dirwalk(char *,void (*fcn)(char *));

/* fsize: print inode # mode,links and size of file "name" */
void fsize(char *name)
{
	struct stat stbuf;
	
	if(stat(name,&stbuf) == -1)
	{
		fprintf(stderr,"fsize: can't access %s \n",name);
		return;
	}
	
	if((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name,fsize);
	printf("%5u %6o %8ld %s\n",stbuf.st_ino,stbuf.st_mode,stbuf.st_nlink,stbuf.st_size,name);

}

