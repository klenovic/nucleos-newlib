#include <nucleos/unistd.h>
#include <machine/syscall.h>
#include <sys/stat.h>
#include <errno.h>

int stat(const char *path, struct stat *buf)
{
	return INLINE_SYSCALL(stat, 2, path, buf);
}
