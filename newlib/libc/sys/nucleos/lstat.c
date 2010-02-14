#include <nucleos/unistd.h>
#include <asm/syscall.h>
#include <sys/stat.h>
#include <errno.h>

int lstat(const char *path, struct stat *buffer)
{
	int err;
	struct kstat kbuffer;

	err = INLINE_SYSCALL(lstat, 2, path, &kbuffer);

	kstat_to_stat(buffer, &kbuffer);

	if (err >= 0) {
		return err;
	}

	return stat(path, buffer);
}
