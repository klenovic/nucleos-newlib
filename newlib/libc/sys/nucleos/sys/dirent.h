#ifndef _SYS_DIRENT_H
#define _SYS_DIRENT_H

#include <sys/types.h>
#include <bits/dirent.h>

/* Definitions for the directory(3) routines: */
typedef struct {
	int dd_fd;	/* Filedescriptor of open directory */
	int dd_loc;	/* Position in _buf */
	int dd_len;	/* bytes in buf */
	char dd_buf[4096];	/* The size does not really
			 * matter as long as the
			 * buffer is big enough 
			 * to contain at least one 
			 * entry.
			 */
} DIR;

/* --- redundant --- */

/* The block size must be at least 1024 bytes, because otherwise
 * the superblock (at 1024 bytes) overlaps with other filesystem data.
 */
#define _MIN_BLOCK_SIZE		1024

/* The below is allocated in some parts of the system as the largest
 * a filesystem block can be. For instance, the boot monitor allocates
 * 3 of these blocks and has to fit within 64kB, so this can't be
 * increased without taking that into account.
 */
#define _MAX_BLOCK_SIZE		4096

/* This is the block size for the fixed versions of the filesystem (V1/V2) */
#define _STATIC_BLOCK_SIZE	1024

#define __dirfd(dir)		(dir)->dd_fd

DIR *opendir(const char *);
struct dirent *readdir(DIR *);
void rewinddir(DIR *);
int closedir(DIR *);

/* internal prototype */
void _seekdir(DIR *dir,off_t offset);
DIR *_opendir(const char *);

#ifndef _POSIX_SOURCE
long telldir (DIR *);
void seekdir (DIR *, off_t loc);

int scandir (const char *__dir,
	     struct dirent ***__namelist,
	     int (*select) (const struct dirent *),
	     int (*compar) (const struct dirent **, const struct dirent **));

int alphasort (const struct dirent **__a, const struct dirent **__b);
#endif /* _POSIX_SOURCE */

#endif /* _SYS_DIRENT_H */
