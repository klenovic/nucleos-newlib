#ifndef _UNISTD_H
#define _UNISTD_H

#include <features.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <_ansi.h>
#include <sys/types.h>
#include <sys/_types.h>
#define __need_size_t
#define __need_ptrdiff_t
#include <stddef.h>

extern char **environ;
extern char *optarg;			/* getopt(3) external variables */
extern int optind, opterr, optopt;
int _EXFUN(getopt,(int, char * const [], const char *));
extern int optreset;			/* getopt(3) external variable */

/* Function Prototypes. */
void _EXFUN(_exit,(int _status));
int _EXFUN(access,(const char *_path, int _amode));
unsigned int _EXFUN(alarm,(unsigned int _seconds));
int _EXFUN(chdir,(const char *_path));
int _EXFUN(fchdir,(int fd));
int _EXFUN(chown,(const char *_path, uid_t _owner, gid_t _group));
int _EXFUN(lchown, (const char *__path, uid_t __owner, gid_t __group ));
int _EXFUN(fchown,(int fd, uid_t _owner, gid_t _group));
int _EXFUN(close,(int _fd));
char _EXFUN(*ctermid,(char *_s));
char _EXFUN(*cuserid,(char *_s));
int _EXFUN(dup,(int _fd));
int _EXFUN(dup2,(int _fd, int _fd2));
int _EXFUN(execl,(const char *_path, const char *_arg, ...));
int _EXFUN(execle,(const char *_path, const char *_arg, ...));
int _EXFUN(execlp,(const char *_file, const char *arg, ...));
int _EXFUN(execv,(const char *_path, char *const _argv[]));
int _EXFUN(execve,(const char *_path, char *const _argv[], char *const _envp[]));
int _EXFUN(execvp,(const char *_file, char *const _argv[]));
pid_t _EXFUN(fork,(void));
long _EXFUN(fpathconf,(int _fd, int _name));
char _EXFUN(*getcwd,(char *_buf, size_t _size));
gid_t _EXFUN(getegid,(void));
uid_t _EXFUN(geteuid,(void));
gid_t _EXFUN(getgid,(void));
int _EXFUN(getgroups,(int _gidsetsize, gid_t _grouplist[]));
char _EXFUN(*getlogin,(void));
pid_t _EXFUN(getpgrp,(void));
pid_t _EXFUN(getpid,(void));
pid_t _EXFUN(getppid,(void));
uid_t _EXFUN(getuid,(void));
int _EXFUN(isatty,(int _fd));
int _EXFUN(link,(const char *_existing, const char *_new));
off_t _EXFUN(lseek,(int _fd, off_t _offset, int _whence));
long _EXFUN(pathconf,(const char *_path, int _name));
int _EXFUN(pause,(void));
int _EXFUN(pipe,(int _fildes[2]));
ssize_t _EXFUN(read,(int _fd, void *_buf, size_t _n));
int _EXFUN(rmdir,(const char *_path));
int _EXFUN(setgid,(gid_t _gid));
int _EXFUN(setegid,(gid_t _gid));
int _EXFUN(setpgid,(pid_t _pid, pid_t _pgid));
pid_t _EXFUN(setsid,(void));
int _EXFUN(setuid,(uid_t _uid));
int _EXFUN(seteuid,(uid_t _uid));
unsigned int _EXFUN(sleep,(unsigned int _seconds));
long _EXFUN(sysconf,(int _name));
pid_t _EXFUN(tcgetpgrp,(int _fd));
int _EXFUN(tcsetpgrp,(int _fd, pid_t _pgrp_id));
char _EXFUN(*ttyname,(int _fd));
int _EXFUN(unlink,(const char *_path));
ssize_t _EXFUN(write,(int _fd, const void *_buf, size_t _n));
int _EXFUN(truncate,(const char *_path, off_t _length));
int _EXFUN(ftruncate,(int _fd, off_t _length));
int _EXFUN(nice,(int _incr));
int _EXFUN(symlink,(const char *path1, const char *path2));
int _EXFUN(readlink,(const char *, char *, size_t));
int _EXFUN(getopt,(int _argc, char * const _argv[], char const *_opts));
int _EXFUN(usleep,(useconds_t _useconds));
int _EXFUN(brk,(void *addr));
int _EXFUN(chroot,(const char *_name));
loff_t _EXFUN(lseek64,(int fd, loff_t offset, int whence));
int _EXFUN(mknod,(const char *_name, mode_t _mode, dev_t _addr));
int _EXFUN(mknod4,(const char *_name, mode_t _mode, dev_t _addr, long _size));
char _EXFUN(*mktemp,(char *_template));
long _EXFUN(ptrace,(int _req, pid_t _pid, long _addr, long _data));
char _EXFUN(*sbrk,(int _incr));
int _EXFUN(sync,(void));
int _EXFUN(fsync,(int fd));
int _EXFUN(reboot,(int _how, ...));
int _EXFUN(gethostname,(char *_hostname, size_t _len));
int _EXFUN(getdomainname,(char *_domain, size_t _len));
char _EXFUN(*getpass, (__const char *__prompt));

/* For compatibility with other Unix systems */
size_t _EXFUN(getpagesize,(void));
int _EXFUN(setgroups,(int ngroups, const gid_t *gidset));
int _EXFUN(initgroups,(const char *name, gid_t basegid));

/* Provide prototypes for most of the _<systemcall> names that are
   provided in newlib for some compilers.  */
int _EXFUN(_close, (int __fildes ));
pid_t _EXFUN(_fork, (void ));
pid_t _EXFUN(_getpid, (void ));
int _EXFUN(_link, (const char *__path1, const char *__path2 ));
off_t _EXFUN(_lseek, (int __fildes, off_t __offset, int __whence ));
_READ_WRITE_RETURN_TYPE _EXFUN(_read, (int __fd, void *__buf, size_t __nbyte ));
void *_EXFUN(_sbrk,  (size_t __incr));
int _EXFUN(_unlink, (const char *__path ));
_READ_WRITE_RETURN_TYPE _EXFUN(_write, (int __fd, const void *__buf, size_t __nbyte ));
int _EXFUN(_execve, (const char *__path, char * const __argv[], char * const __envp[] ));

#define	F_OK	0
#define	R_OK	4
#define	W_OK	2
#define	X_OK	1

# define	SEEK_SET	0
# define	SEEK_CUR	1
# define	SEEK_END	2

#include <sys/features.h>

#define STDIN_FILENO	0       /* standard input file descriptor */
#define STDOUT_FILENO	1       /* standard output file descriptor */
#define STDERR_FILENO	2       /* standard error file descriptor */

#define MAXPATHLEN	255	/* @nucleos: PATH_MAX value */

/* The following relate to configurable system variables. POSIX Table 4-2. */
#define _SC_ARG_MAX		1
#define _SC_CHILD_MAX		2
#define _SC_CLOCKS_PER_SEC	3
#define _SC_CLK_TCK		3
#define _SC_NGROUPS_MAX		4
#define _SC_OPEN_MAX		5
#define _SC_JOB_CONTROL		6
#define _SC_SAVED_IDS		7
#define _SC_VERSION		8
#define _SC_STREAM_MAX		9
#define _SC_TZNAME_MAX		10
#define _SC_PAGESIZE		11
#define _SC_PAGE_SIZE		_SC_PAGESIZE

/* The following relate to configurable pathname variables. POSIX Table 5-2. */
#define _PC_LINK_MAX		1    /* link count */
#define _PC_MAX_CANON		2    /* size of the canonical input queue */
#define _PC_MAX_INPUT		3    /* type-ahead buffer size */
#define _PC_NAME_MAX		4    /* file name size */
#define _PC_PATH_MAX		5    /* pathname size */
#define _PC_PIPE_BUF		6    /* pipe size */
#define _PC_NO_TRUNC		7    /* treatment of long name components */
#define _PC_VDISABLE		8    /* tty disable */
#define _PC_CHOWN_RESTRICTED	9  /* chown restricted or not */

/* POSIX defines several options that may be implemented or not, at the
 * implementer's whim.  This implementer has made the following choices:
 *
 * _POSIX_JOB_CONTROL       not defined:        no job control
 * _POSIX_SAVED_IDS         not defined:        no saved uid/gid
 * _POSIX_NO_TRUNC          defined as -1:      long path names are truncated
 * _POSIX_CHOWN_RESTRICTED  defined:            you can't give away files
 * _POSIX_VDISABLE          defined:            tty functions can be disabled
 */
#ifdef __cplusplus
}
#endif
#endif /* _SYS_UNISTD_H */
