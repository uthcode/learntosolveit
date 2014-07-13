/*Modify the fsize program to print the other information contained in the inode entry
 *
 * Fails compilation
 *
 * TODO:
 * Override stdlib functions.
 *
 * */

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include"dirent.h"

#define NAME_MAX 14		/* longest filename component */
#define MAX_PATH 1024

int stat(char *,struct stat *);
void dirwalk(char *,void (*fcn)(char *));
void fsize(char *);

typedef struct {  /* portable directory entry */
	long ino;		/* inode number */
	char name[NAME_MAX + 1];	/* name + \0 terminator */
} Dirent;

typedef struct {  /* minimal DIR: no buferring, etc */
	int fd;		/* file descriptor for directory */
	Dirent d;	/* the directory entry */

} DIR;


struct stat			/* inode information returned by stat */
{
	dev_t 	st_dev;	/* device of inode */
	ino_t	st_ino;	/* inode number */
	short	st_mode;	/* mode bits */
	short	st_nlink;	/* number of links to file */
	short	st_uid;		/* owners user id */
	short	st_gid;		/* owners group id */
	dev_t	st_rdev;	/* for special files */
	off_t	st_size;	/* file size in characters*/
};

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



/*dirwalk: apply fcn to all files in the dir */

void dirwalk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH];
	Dirent *dp;
	DIR *dfd;

	if ((dfd = opendir(dir)) == NULL) {
		fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return;
	}

	while ((dp = readdir(dfd)) != NULL) {
		if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, ".."))
			continue;	/* skip for self and parent */
		if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
			fprintf(stderr, "d: walk: name %s/%s too long\n", dir, dp->name);
		else {
			sprintf(name, "%s/%s", dir, dp->name);
			(*fcn)(name);
		}

	}
	closedir(dfd);
}

/* print file sizes with more information */

int main(int argc, char *argv[]) {
	if (argc == 1)		/* default: current directory */
		fsize(".");
	else
		while (--argc > 0)
			fsize(*++argv);
	return 0;
}
