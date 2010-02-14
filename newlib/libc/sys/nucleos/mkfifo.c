#include <unistd.h>
#include <sys/stat.h>

int mkfifo(const char *name, mode_t mode)
{
	return mknod(name, mode | S_IFIFO, (dev_t) 0);
}
