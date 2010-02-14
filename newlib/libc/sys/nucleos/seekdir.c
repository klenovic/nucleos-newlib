#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

int seekdir(DIR *dp, off_t pos)
/* Seek to position pos in a directory. */
{
	int off;

	if (dp == 0) { errno = EBADF; return -1; }

	dp->dd_len= 0;

	if (lseek(dp->dd_fd, pos, SEEK_SET) == -1) return -1;

	return 0;
}
