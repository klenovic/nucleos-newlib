#include <sys/types.h>
#include <dirent.h>

void rewinddir(DIR *dp)
{
	(void) seekdir(dp, 0);
}
