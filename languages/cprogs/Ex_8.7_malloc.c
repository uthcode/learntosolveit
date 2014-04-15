/* malloc accepts a size request without checking its plausiblity; free believes
 that the block it is asked to free contain a valid size field. Improve these rountines so they take more pains with error checking */

#define MAXBYTES	(unsigned)10240
	
static unsigned maxalloc;	/* max number of units allocated */
static Header	 base;	/* empty list to get started */
static Header	*freep = NULL;	/*start of free list */

/* malloc: general purpose storage allocator */

void *malloc(unsigned nbytes)
{
	Header *p,*prevp;
	static Header *morecore(unsigned);
	unsigned nunits;

	if(nbytes > MAXBYTES)
	{
		fprintf(stderr,"alloc: can't allocate more than %u bytes\n",MAXBYTES);
		return NULL;
	}
	nunits = (nbyte	+ sizeof(Header) -1) / sizeof(Header) +1;

	if((prevp = freep) == NULL) 
	{
		base.s.prt = freep = prevp = &base;
		base.s.size = 0;
	}
	for(p = prevp->s.ptr ; ; prevvp = p,p = p ->s.ptr)
	{
		if(p->s.size >= nunit)
		{
		if (p->s.size == nunits)
			prev->s.ptr = p->s.ptr;
		else
		{
			p->s.size -= nunits;	
			p += p->s.size;
			p->s.size = nunits;
		}
		freep(prevp);
	return (void *)(p+1);
	}

	if(p == freep)	/* wrapped around free list */
		if((p = morecore(units)) == NULL)
			return NULL;
	}
}
	
