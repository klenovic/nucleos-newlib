#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dirent.h>
#include <sys/fcntl.h>

DIR *opendir(const char *name)
/* Open a directory for reading. */
{
	int d, f;
	DIR *dp;
	struct stat st;

	/* Only read directories. */
	if (stat(name, &st) < 0) return 0;
	if (!S_ISDIR(st.st_mode)) { errno= ENOTDIR; return 0; }

	if ((d = open(name, O_RDONLY | O_NONBLOCK)) < 0) return 0;

	/* Check the type again, mark close-on-exec, get a buffer. */
	if (fstat(d, &st) < 0
		|| (errno = ENOTDIR, !S_ISDIR(st.st_mode))
		|| (f = fcntl(d, F_GETFD)) < 0
		|| fcntl(d, F_SETFD, f | FD_CLOEXEC) < 0
		|| (dp = (DIR *) malloc(sizeof(*dp))) == 0
	) {
		int err = errno;
		(void) close(d);
		errno = err;
		return 0;
	}

	dp->dd_fd = d;
	dp->dd_len = 0;
	dp->dd_loc = 0;

	return dp;
}
