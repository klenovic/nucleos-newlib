#include <nucleos/unistd.h>
#include <asm/syscall.h>

extern void *__curbrk;

char *sbrk(int incr)
{
  char *newsize, *oldsize;

  oldsize = __curbrk;
  newsize = __curbrk + incr;
  if ((incr > 0 && newsize < oldsize) || (incr < 0 && newsize > oldsize))
	return( (char *) -1);
  if (brk(newsize) == 0)
	return(oldsize);
  else
	return( (char *) -1);
}
