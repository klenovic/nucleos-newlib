#ifndef	_SYS_STAT_H
#define	_SYS_STAT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <asm/stat.h>
#include <_ansi.h>
#include <time.h>
#include <sys/types.h>

/* dj's stat defines _STAT_H_ */
#ifndef _STAT_H_

/* Traditional mask definitions for st_mode. */
#define S_IFMT		0170000	/* type of file */
#define S_IFLNK		0120000	/* symbolic link */
#define S_IFREG		0100000	/* regular */
#define S_IFBLK		0060000	/* block special */
#define S_IFDIR		0040000	/* directory */
#define S_IFCHR		0020000	/* character special */
#define S_IFIFO		0010000	/* this is a FIFO */
#define S_ISUID		0004000	/* set user id on execution */
#define S_ISGID		0002000	/* set group id on execution */
                                /* next is reserved for future use */
#define S_ISVTX		01000	/* save swapped text even after use */
/* not used */
#define S_IFSOCK	0140000	/* socket */

/* POSIX masks for st_mode. */
#define S_IRWXU		00700	/* owner:  rwx------ */
#define S_IRUSR		00400	/* owner:  r-------- */
#define S_IWUSR		00200	/* owner:  -w------- */
#define S_IXUSR		00100	/* owner:  --x------ */

#define S_IRWXG		00070	/* group:  ---rwx--- */
#define S_IRGRP		00040	/* group:  ---r----- */
#define S_IWGRP		00020	/* group:  ----w---- */
#define S_IXGRP		00010	/* group:  -----x--- */

#define S_IRWXO		00007	/* others: ------rwx */
#define S_IROTH		00004	/* others: ------r-- */
#define S_IWOTH		00002	/* others: -------w- */
#define S_IXOTH		00001	/* others: --------x */

/* Synonyms for above. */
#define S_IEXEC		S_IXUSR
#define S_IWRITE	S_IWUSR
#define S_IREAD		S_IRUSR

/* The following macros test st_mode (from POSIX Sec. 5.6.1.1). */
#define S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)     /* is a reg file */
#define S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)     /* is a directory */
#define S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)     /* is a char spec */
#define S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)     /* is a block spec */
#define S_ISLNK(m)	(((m) & S_IFMT) == S_IFLNK)     /* is a symlink */
#define S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)     /* is a pipe/FIFO */
#define S_ISSOCK(m)	(((m) & S_IFMT) == S_IFSOCK)     /* is a pipe/FIFO */

int	_EXFUN(chmod,( const char *__path, mode_t __mode ));
int     _EXFUN(fchmod,(int __fd, mode_t __mode));
int	_EXFUN(fstat,( int __fd, struct stat *__sbuf ));
int	_EXFUN(mkdir,( const char *_path, mode_t __mode ));
int	_EXFUN(mkfifo,( const char *__path, mode_t __mode ));
int	_EXFUN(stat,( const char *__path, struct stat *__sbuf ));
mode_t	_EXFUN(umask,( mode_t __mask ));
int	_EXFUN(lstat,( const char *__path, struct stat *__buf ));

/* Provide prototypes for most of the _<systemcall> names that are
   provided in newlib for some compilers.  */
#ifdef _COMPILING_NEWLIB
int	_EXFUN(_fstat,( int __fd, struct stat *__sbuf ));
int	_EXFUN(_stat,( const char *__path, struct stat *__sbuf ));
#ifdef __LARGE64_FILES
struct stat64;
int	_EXFUN(_fstat64,( int __fd, struct stat64 *__sbuf ));
#endif
#endif

#endif /* !_STAT_H_ */
#ifdef __cplusplus
}
#endif
#endif /* _SYS_STAT_H */
