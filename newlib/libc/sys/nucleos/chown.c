#include <nucleos/unistd.h>
#include <machine/syscall.h>
#include <sys/errno.h>
#include <sys/types.h>

int chown(const char *name, uid_t owner, gid_t grp)
{
	return INLINE_SYSCALL(chown, 3, name, owner, grp);
}
