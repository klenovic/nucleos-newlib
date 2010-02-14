#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/dirent.h>

int closedir(DIR *dp)
/* Finish reading a directory. */
{
	int d;

	if (dp == 0) { errno= EBADF; return -1; }

	d= dp->dd_fd;

	free((void *) dp);

	return close(d);
}
