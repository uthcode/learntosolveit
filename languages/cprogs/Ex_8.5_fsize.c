#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define NAME_MAX 14

typedef struct {
	long ino;
	char name[NAME_MAX + 1];
} Dirent;

typedef struct {
	int fd;
	Dirent d;
} MYDIR;

MYDIR *myopendir(char *dirname);

Dirent *myreaddir(MYDIR *dfd);

void myclosedir(MYDIR *dfd);


void fsize(char *);
void dirwalk(char *, void (*fcn)(char *));

/* stat from sys.stat.h has the following structure and these fields can be accessed.
 *
struct stat {
	dev_t	 	st_dev;		 [XSI] ID of device containing file
	ino_t	  	st_ino;		 [XSI] File serial number
	mode_t	 	st_mode;	 [XSI] Mode of file (see below)
	nlink_t		st_nlink;	 [XSI] Number of hard links
	uid_t		st_uid;		 [XSI] User ID of the file
	gid_t		st_gid;		 [XSI] Group ID of the file
	dev_t		st_rdev;	 [XSI] Device ID
#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
	struct	timespec st_atimespec;	 time of last access
	struct	timespec st_mtimespec;	 time of last data modification
	struct	timespec st_ctimespec;	 time of last status change
#else
	time_t		st_atime;	 [XSI] Time of last access
	long		st_atimensec;	 nsec of last access
	time_t		st_mtime;	 [XSI] Last data modification time
	long		st_mtimensec;	 last data modification nsec
	time_t		st_ctime;	 [XSI] Time of last status change
	long		st_ctimensec;	 nsec of last status change
#endif
	off_t		st_size;	 [XSI] file size, in bytes
	blkcnt_t	st_blocks;	 [XSI] blocks allocated for file
	blksize_t	st_blksize;	 [XSI] optimal blocksize for I/O
	__uint32_t	st_flags;	 user defined flags for file
	__uint32_t	st_gen;		 file generation number
	__int32_t	st_lspare;	 RESERVED: DO NOT USE!
	__int64_t	st_qspare[2];	 RESERVED: DO NOT USE!
};
*/


/*fsize: print size of file "name" */
void fsize(char *name) {
	struct stat stbuf;

	if (stat(name, &stbuf) == -1) {
		fprintf(stderr, "fsize: can't access %s\n", name);
		return;
	}

	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name, fsize);

	printf("%8ld - %8ld - %8ld - %8ld - %8ld - %8ld %s\n", stbuf.st_size, stbuf.st_blocks, stbuf.st_blksize, stbuf.st_flags, stbuf.st_gen, stbuf.st_nlink, name);

}

#define MAX_PATH 1024

void dirwalk(char *dir, void (*fcn)(char *)) {
	char name[MAX_PATH];
	Dirent *dp;
	MYDIR *dfd;

	if ((dfd = myopendir(dir)) == NULL) {
		fprintf(stderr, "dirwalk: cant open %s\n", dir);
		return;
	}

	while((dp = myreaddir(dfd)) != NULL) {
		if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
			continue;
		if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
			fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->name);
		else {
			sprintf(name, "%s/%s", dir, dp->name);
			(*fcn)(name);
		}

	}
	myclosedir(dfd);
}

#ifndef DIRSIZ
#define DIRSIZE 14
#endif

struct direct {  /* directory entry */
	ino_t d_ino;
	char d_name[DIRSIZE];

};


MYDIR *myopendir(char *dirname) {
	int fd;
	struct stat stbuf;
	MYDIR *dp;

	if ((fd = open(dirname, O_RDONLY, 0)) == -1 || fstat(fd, &stbuf) == -1 || (stbuf.st_mode & S_IFMT) != S_IFDIR || (dp = (MYDIR *) malloc(sizeof(MYDIR))) == NULL)
		return NULL;
	dp->fd = fd;
	return dp;

}

void myclosedir(MYDIR *dp) {
	if (dp) {
		close(dp->fd);
		free(dp);
	}
}

#include <sys/dir.h>


#define DIRSIZE 14


Dirent *myreaddir(MYDIR *dp) {
	struct direct dirbuf;
	static Dirent d;

	while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
		if (dirbuf.d_ino == 0)
			continue;
		d.ino = dirbuf.d_ino;
		strncpy(d.name, dirbuf.d_name, DIRSIZE);
		d.name[DIRSIZE] = '\0';
		return &d;
	}
	return NULL;
}

int main(int argc, char *argv[]) {
	if (argc == 1)
		fsize(".");
	else
		while (--argc > 0)
			fsize(*++argv);
	return 0;
}
