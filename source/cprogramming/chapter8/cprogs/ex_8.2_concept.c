/* Concept: FILE flag bits — _READ/_WRITE/_EOF/_ERR encoded as bit fields */
#include <stdio.h>
int main(void) {
    int _READ = 01, _WRITE = 02, _EOF = 010, _ERR = 020;
    int flag;
    /* stdin-like: read-only */
    flag = _READ;
    printf("stdin: readable=%d writable=%d\n",
           (flag & _READ)  != 0, (flag & _WRITE) != 0);
    /* stdout-like: write-only */
    flag = _WRITE;
    printf("stdout: readable=%d writable=%d\n",
           (flag & _READ)  != 0, (flag & _WRITE) != 0);
    /* simulate EOF reached */
    flag |= _EOF;
    printf("after EOF: eof=%d err=%d\n",
           (flag & _EOF) != 0, (flag & _ERR) != 0);
    return 0;
}
