/* The emulation of lchown*/
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>

int lchown(const char *path, uid_t owner, gid_t group)
{
	struct stat st;

	if (lstat(path, &st) == -1)
		return -1;

	if (S_ISLNK(st.st_mode))
		return 0;

	return (chown(path, owner, group));
}
