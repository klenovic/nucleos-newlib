#include <nucleos/unistd.h>
#include <machine/syscall.h>
#include <sys/stat.h>
#include <errno.h>

int fstat(int fd, struct stat *buf)
{
	return INLINE_SYSCALL(fstat, 2, fd, buf);
}
