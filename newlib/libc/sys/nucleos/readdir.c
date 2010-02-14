#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dirent.h>
#include <sys/fcntl.h>

struct dirent *readdir(DIR *dp)
/* Return the next entry in a directory. */
{
	struct dirent *entp;
	int count, pos, reclen;

	if (dp == 0) {
		errno= EBADF;
		return 0;
	}

	count = dp->dd_len;
	pos = dp->dd_loc;

	if (count == 0 || pos >= count) {
		count = getdents(dp->dd_fd, (struct dirent *)dp->dd_buf, sizeof(dp->dd_buf));

		if (count <= 0)
			return 0;

		dp->dd_len = count;
		dp->dd_loc = pos = 0;
	}

	entp = (struct dirent *)&((char *)dp->dd_buf)[pos];
	reclen = entp->d_reclen;
	dp->dd_loc= pos + reclen;

	return entp;
}
