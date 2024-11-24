#include <stdlib.h>
#include <unistd.h>

#ifdef NULL
#undef NULL
#endif

#define NULL 0
#define EOF (-1)
#define BUFSIZE 1024
#define OPEN_MAX 20 /* max # files open at once */

typedef struct _iobuf {
    int cnt;    /* characters left */
    char *ptr;  /* next character position */
    char *base; /* location of the buffer */
    int flag;   /* mode of the file access */
    int fd;     /* file descriptor */
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags {
    _READ = 01,
    /* file open for reading */ /* binary 1 */
    _WRITE = 02,
    /* file open for writing */ /* binary 10 */
    _UNBUF = 03,
    /* file is unbuffered */ /* binary 11 */
    _EOF = 010,
    /* EOF has occurred on this file */ /* binary 1000 */
    _ERR = 020,
    /* error occurred on this file */ /* binary 10000*/
};

int _fillbuf(FILE *);

int _flushbuf(int, FILE *);

#define getc(p) (--(p)->cnt >= 0 ? (unsigned char)*(p)->ptr++ : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x), p))
#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

/* _fillbuf: allocate and fill input buffer */

int _fillbuf(FILE *fp) {
    int bufsize;

    /* this is a bit operation */

    if ((fp->flag & (_READ | _EOF | _ERR)) != _READ)
        return EOF;

    /* this is a bit operation */

    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZE;

    if (fp->base == NULL) /* no buffer yet */
        if ((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF; /* can't get buffer */

    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);

    /* these are bit operations */

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
        if ((f->base = malloc(BUFSIZE)) == NULL)
            /* could not allocate a buffer, so try unbuffered */
            f->flag |= _UNBUF;
        else {
            f->ptr = f->base;
            f->cnt = BUFSIZE - 1;
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
        /*if ( c!= EOF) {
                f->ptr = uc;
        } */
        bufsize = (int) (f->ptr - f->base);
        num_written = write(f->fd, f->base, bufsize);
        f->ptr = f->base;
        f->cnt = BUFSIZE - 1;
    }

    if (num_written == bufsize)
        return c;
    else {
        f->flag |= _ERR;
        return EOF;
    }
}

FILE _iob[OPEN_MAX] = {/* stdin, stdout, stderr */
        {0, (char *) 0, (char *) 0, _READ,           0},
        {0, (char *) 0, (char *) 0, _WRITE,          1},
        {0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2}};

int main(int argc, char *argv[]) {
    int c;
    while ((c = getchar()) != 'x') {
        putchar(c);
    }
}