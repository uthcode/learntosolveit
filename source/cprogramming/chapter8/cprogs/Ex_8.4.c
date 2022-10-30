#include <fcntl.h>
#include <stdarg.h>
// The functions available from stdio.h are implemented here.
//#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

#ifdef NULL
#undef NULL
#endif

#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20 /* max # files open at once */

typedef struct _iobuf {
	int cnt;		/* characters left */
	char *ptr;		/* next character position */
	char *base;		/* location of the buffer */
	int flag;		/* mode of the file access */
	int fd;			/* file descriptor */
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin	(&_iob[0])
#define stdout	(&_iob[1])
#define stderr	(&_iob[2])

enum _flags {
	_READ = 01,		/* file open for reading */
	_WRITE = 02,	/* file open for writing */
	_UNBUF = 03,	/* file is unbuffered */
	_EOF	= 010,	/* EOF has occurred on this file */
	_ERR	= 020,	/* error occurred on this file */
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p)		(((p)->flag & _EOF) != 0)
#define ferror(p)	(((p)->flag & _ERR) != 0)
#define fileno(p)	((p)->fd)

#define	getc(p)	(--(p)->cnt >= 0 \
				? (unsigned char) *(p)->ptr++ : _fillbuf(p))

#define putc(x, p) (--(p)->cnt >= 0 \
				? *(p)->ptr++ = (x) : _flushbuf((x), p))

#define getchar()  	getc(stdin)
#define putchar(x)	putc((x), stdout)

#define PERMS 0666	/* RW for owner, group and others */

/* fopen: open file, return file ptr */

FILE *fopen(char *name, char *mode)
{
	int fd;
	FILE *fp;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;


	for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if ( (fp->flag & (_READ | _WRITE)) == 0)
			break;	/* found free slot */

	if (fp >= _iob + OPEN_MAX)	/* no free slots */
		return NULL;

	if (*mode == 'w')
		fd = creat(name, PERMS);
	else if (*mode == 'a') {
		if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	} else
		fd = open(name, O_RDONLY, 0);

	if (fd == -1)	/* couldn't access name */
		return NULL;

	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->flag = (*mode == 'r') ? _READ : _WRITE;
	return fp;
}


/* _fillbuf: allocate and fill input buffer */

int _fillbuf(FILE *fp)
{
	int bufsize;

	if ((fp->flag & (_READ | _EOF | _ERR)) != _READ)
		return EOF;

	bufsize = (fp->flag & _UNBUF) ? 1: BUFSIZ;

	if  (fp->base == NULL)	/* no buffer yet */
		if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF;		/* can't get buffer */

	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);

	if (--fp->cnt < 0) {
		if (fp->cnt == -1)
			fp->flag |= _EOF;
		else
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF;
	}

	return (unsigned char) *fp->ptr++;
}

/* _flushbuf: flush a buffer */
/* http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_8:Exercise_3 */

int _flushbuf(int c, FILE *f) {
	int num_written, bufsize;
	unsigned char uc = c;

	if ((f->flag & (_WRITE | _EOF | _ERR)) != _WRITE) {
		return EOF;
	}

	if (f->base == NULL && ((f->flag & _UNBUF) == 0)) {
		/* no buffer yet */
		if ((f->base = malloc(BUFSIZ)) == NULL)
			/* could not allocate a buffer, so try unbuffered */
			f->flag |= _UNBUF;
		else {
			f->ptr = f->base;
			f->cnt = BUFSIZ - 1;
		}
	}

	if (f->flag & _UNBUF) {
		/* unbuffered write */
		f->ptr = f->base = NULL;
		f->cnt = 0;
		if (c == EOF) {
			return EOF;
		}
		num_written = write(f->fd, &uc, 1);
		bufsize = 1;
	} else {
		/* buffered write */
		/* TODO: Senthil Kumaran - What should be the f-> ptr?*/
		/*if ( c!= EOF) {
			f->ptr = uc;
		} */
		bufsize = (int)(f->ptr - f->base);
		num_written = write(f->fd, f->base, bufsize);
		f->ptr = f->base;
		f->cnt = BUFSIZ - 1;
	}

	if (num_written == bufsize)
		return c;
	else {
		f->flag |= _ERR;
		return EOF;
	}
}

FILE _iob[OPEN_MAX] = {		/* stdin, stdout, stderr */
		{ 0, (char *) 0, (char *) 0, _READ, 0 },
		{ 0, (char *) 0, (char *) 0, _WRITE, 1 },
		{ 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};


/* fflush */
int fflush(FILE *f) {
	int retval;
	int i;
	FILE *fp;

	retval = 0;

	if (f == NULL) {
		/* flush all the output streams */

		for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
			if ( (fp->flag &  _WRITE) == 0 && fflush(fp) == -1)
				retval = -1;
	} else {
		if ((f->flag & _WRITE) == 0)
			return -1;
		_flushbuf(EOF, f);
		if (f->flag & _ERR)
			retval = -1;
	}
	return retval;
}


/* fclose */

int fclose(FILE *f)
{
	int fd;

	if (f == NULL)
		return -1;

	fd = f->fd;
	fflush(f);
	f->cnt = 0;
	f->ptr = NULL;
	if (f->base != NULL)
		free(f->base);
	f->base = NULL;
	f->flag = 0;
	f->fd = -1;
	return close(fd);
}

/* fseek */
/* http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_8:Exercise_4 */
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

int fseek(FILE *f, long offset, int whence) {
	int result;

	if ((f->flag & _UNBUF) == 0 && f->base != NULL) {
		/* deal with buffering */
		if (f->flag & _WRITE) {
			if (fflush(f))
				return EOF;
		} else if (f->flag & _READ) {
			/* Reading so thrash buffer, do some housekeeping first
			 */
			if (whence == SEEK_CUR) {
				/* fix offset so that it's from the last
				 * character the user read (not the last character that was
				 * actually read)
				 */
				if (offset >=0 && offset <= f->cnt) {
					/* easy shortcut */
					f->cnt -= offset;
					f->ptr += offset;
					f->flag &= ~_EOF; /* If successful, clear EOF */
					return 0;
				} else {
					offset -= f->cnt;
				}
			}
			f->cnt = 0;
			f->ptr = f->base;
		}
	}

	result = (lseek(f->fd, offset, whence) < 0);

	if (result == 0)
		f->flag &= ~_EOF; /* If successful, clear EOF */
	return result;
}

int main(int argc, char *argv[]) {
	int c;
	while ((c =getchar()) != 'x') {
		putchar(c);
	}
}
