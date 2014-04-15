/* Write a routine bfree(p,n) that will free an arbitraty block p of n characters into the free list maintained by alloc by free */

unsigned bfree(char *p,unsigned n)
{
	Header *hp;
	
	if(n < sizeof(Header))
		return 0;
	
	hp = (Header *)p;
	hp->s.size = n / sizeof(Header);
	free((void *)(hp+1));

	return no->s.slides;
}

