#include <nucleos/unistd.h>
#include <asm/syscall.h>
#include <sys/stat.h>
#include <errno.h>

int fstat(int fd, struct stat *buf)
{
	int err;
	struct kstat kbuf;

	err = INLINE_SYSCALL(fstat, 2, fd, &kbuf);

	kstat_to_stat(buf, &kbuf);

	return err;
}
