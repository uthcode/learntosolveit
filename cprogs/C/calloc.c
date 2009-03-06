/* The standard library function calloc(n,size) returns a pointer to n objects if size size, with the storage intialized to zero. Write calloc,by callinng malloc or modifying it */

/* calloc: allocate n objects of size size */
void *calloc(unsigned n,unsigned size)
{
	unsigned i,nb;
	char *p,*q;

	nb = n * size;
	
	if((p = q = malloc(nb)) != NULL)
		for(i = 0; i <nb; i++)
			*p++ = 0;
	return q;

}

