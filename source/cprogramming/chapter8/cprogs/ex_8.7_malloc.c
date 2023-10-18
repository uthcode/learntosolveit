/* malloc accepts a size request without checking its plausiblity; free believes
 that the block it is asked to free contain a valid size field. Improve these
 rountines so they take more pains with error checking */

#include <stdio.h>
#include <stdlib.h>

#define MAXBYTES (unsigned)10240
#define NALLOC 1024

typedef long Align;

union header {
    struct {
        union header *ptr; /* next block if on free list */
        unsigned size;     /* size of this block */
    } s;
};

typedef union header Header;

static unsigned maxalloc;    /* max number of units allocated */
static Header base;          /* empty list to get started */
static Header *freep = NULL; /*start of free list */

/* morecore: ask system for more memory */

static Header *morecore(unsigned nu) {
    char *cp, *sbrk(int);
    Header *up;

    if (nu < NALLOC)
        nu = NALLOC;

    cp = sbrk(nu * sizeof(Header));
    if (cp == (char *) -1) /* no space at all */
        return NULL;

    up = (Header *) cp;
    up->s.size = nu;
    free((void *) (up + 1));
    return freep;
}

/* malloc: general purpose storage allocator */

void *mymalloc(unsigned nbytes) {
    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;

    if (nbytes > MAXBYTES) {
        fprintf(stderr, "alloc: can't allocate more than %u bytes\n", MAXBYTES);
        return NULL;
    }
    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

    if ((prevp = freep) == NULL) {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    for (p = prevp->s.ptr;; prevp = p, p = p->s.ptr) {
        if (p->s.size >= nunits) {
            if (p->s.size == nunits)
                prevp->s.ptr = p->s.ptr;
            else {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *) (p + 1);
        }

        if (p == freep) /* wrapped around free list */
            if ((p = morecore(nunits)) == NULL)
                return NULL;
    }
}

/* free: put a block ap in free list */

void free(void *ap) {
    Header *bp, *p;

    bp = (Header *) ap - 1; /* point to block header */
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break; /* freed block at start or end of arena */

    if (bp + bp->s.size == p->s.ptr) { /* join to upper nbr */
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else
        bp->s.ptr = p->s.ptr;

    if (p + p->s.size == bp) { /* join to lower nbr */
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else
        p->s.ptr = bp;

    freep = p;
}

int main(int argc, char *argv[]) {
    int *p = NULL;
    int i = 0;

    p = mymalloc(1000);
    if (NULL == p) {
        printf("mymalloc returned NULL");

    } else {
        for (i = 0; i <= 100; i++) {
            printf("%08X", p[i]);
            if (i % 8 == 7) {
                printf("\n");
            }
        }
        printf("\n");
        free(p);
    }
    return 0;
}
