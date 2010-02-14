#include <nucleos/unistd.h>
#include <asm/syscall.h>
#include <sys/stat.h>
#include <errno.h>

int stat(const char *path, struct stat *buf)
{
	struct kstat kbuf;
	int err;

	err = INLINE_SYSCALL(stat, 2, path, &kbuf);

	kstat_to_stat(buf, &kbuf);

	return err;
}
