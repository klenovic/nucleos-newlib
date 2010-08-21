#include <nucleos/unistd.h>
#include <machine/syscall.h>
#include <sys/stat.h>
#include <errno.h>

int lstat(const char *path, struct stat *buffer)
{
	int err;

	err = INLINE_SYSCALL(lstat, 2, path, buffer);

	if (err >= 0)
		return err;

	return stat(path, buffer);
}
