/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

//#include <_ansi.h>

/* ask gcc for */
#define __need_size_t
#include <stddef.h>
#include <sys/config.h>
#include <features.h>
#include <machine/types.h>
#include <sys/_types.h>

#ifndef __clock_t_defined
typedef _CLOCK_T_ clock_t;
#define __clock_t_defined
#endif

#ifndef __time_t_defined
typedef _TIME_T_ time_t;
#define __time_t_defined
#endif /* __time_t_defined */

#ifndef _SSIZE_T
#define _SSIZE_T
typedef _ssize_t ssize_t;
#endif

/* We don't define fd_set and friends if we are compiling POSIX
   source, or if we have included (or may include as indicated
   by __USE_W32_SOCKETS) the W32api winsock[2].h header which
   defines Windows versions of them.   Note that a program which
   includes the W32api winsock[2].h header must know what it is doing;
   it must not call the cygwin32 select function.
*/
#define _SYS_TYPES_FD_SET
#define NBBY	8		/* number of bits in a byte */
/*
 * Select uses bit masks of file descriptors in longs.
 * These macros manipulate such bit fields (the filesystem macros use chars).
 * FD_SETSIZE may be defined by the user, but the default here
 * should be >= NOFILE (param.h).
 */
#ifndef FD_SETSIZE
/* nucleos: set to 32 */
#define FD_SETSIZE	32
#endif

typedef	long	fd_mask;
# define	NFDBITS	(sizeof (fd_mask) * NBBY)	/* bits per mask */

#ifndef howmany
#define howmany(x,y)	(((x)+((y)-1))/(y))
#endif

/* We use a macro for fd_set so that including Sockets.h afterwards
   can work.  */
typedef	struct {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} __fd_set;

#  define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#  define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#  define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#  define	FD_ZERO(p)	(__extension__ (void)({ \
     size_t __i; \
     char *__tmp = (char *)p; \
     for (__i = 0; __i < sizeof (*(p)); ++__i) \
       *__tmp++ = 0; \
}))

#include <nucleos/types.h>
#include <bits/types.h>

#define __mode_t_defined
#define __gid_t_defined
#define __uid_t_defined
#define __pid_t_defined
#define __ssize_t_defined
#define __key_t_defined
#define __off_t_defined

#ifndef __clock_t_defined
#define __clock_t_defined
typedef __kernel_clock_t	clock_t;
#endif

typedef __kernel_mode_t		mode_t;
typedef __kernel_gid_t		gid_t;
typedef __kernel_uid_t		uid_t;
typedef __kernel_pid_t		pid_t;

#ifndef _SSIZE_T
#define _SSIZE_T
typedef __kernel_ssize_t	ssize_t;
#endif

typedef __kernel_off_t		off_t;
typedef __kernel_fd_set		fd_set;
typedef __kernel_ino_t		ino_t;
typedef __s16	__kernel_dev_t;
typedef __kernel_dev_t		dev_t;          /* holds (major|minor) device pair */
typedef __kernel_useconds_t	useconds_t;
#if defined(__GNUC__)
typedef __kernel_loff_t		loff_t;
#endif

typedef long suseconds_t;
typedef	long key_t;

typedef __kernel_caddr_t	caddr_t;

typedef unsigned long		blkcnt_t;
typedef unsigned long		blksize_t;

//typedef _Bool			bool;

/* @klenovic: don't use these below (will be removed) */
typedef __u8  u8;       /* 8 bit type */
typedef __u16 u16;      /* 16 bit type */
typedef __u32 u32;      /* 32 bit type */

typedef __s8  i8;       /* 8 bit signed type */
typedef __s16 i16;      /* 16 bit signed type */
typedef __s32 i32;      /* 32 bit signed type */
typedef __u64 u64;

typedef __u8  u8_t;       /* 8 bit type */
typedef __u16 u16_t;      /* 16 bit type */
typedef __u32 u32_t;      /* 32 bit type */

typedef __s8  i8_t;       /* 8 bit signed type */
typedef __s16 i16_t;      /* 16 bit signed type */
typedef __s32 i32_t;      /* 32 bit signed type */
typedef __u64 u64_t;
/* ! */

/* use <bits/types.h> */
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;

typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;

typedef __uint32_t uintptr_t;
typedef __uint32_t intptr_t;

#ifndef _UINT8_T_DECLARED
typedef __uint8_t	uint8_t;
#define _UINT8_T_DECLARED
#endif

#ifndef _UINT16_T_DECLARED
typedef __uint16_t	uint16_t;
#define _UINT16_T_DECLARED
#endif

#ifndef _UINT32_T_DECLARED
typedef __uint32_t	uint32_t;
#define _UINT32_T_DECLARED
#endif

#ifndef _UINT64_T_DECLARED
typedef __uint64_t	uint64_t;
#define _UINT64_T_DECLARED
#endif

/* Signal handler type, e.g. SIG_IGN */
typedef void (*sighandler_t)(int);

/* Devices. */
#define MAJOR              8    /* major device = (dev>>MAJOR) & 0377 */
#define MINOR              0    /* minor device = (dev>>MINOR) & 0377 */

#ifndef minor
#define minor(dev)      (((dev) >> MINOR) & 0xff)
#endif

#ifndef major
#define major(dev)      (((dev) >> MAJOR) & 0xff)
#endif

#ifndef makedev
#define makedev(major, minor)   \
                        ((dev_t) (((major) << MAJOR) | ((minor) << MINOR)))
#endif

typedef long daddr_t;
typedef unsigned short nlink_t;

#ifndef __clockid_t_defined
typedef _CLOCKID_T_ clockid_t;
#define __clockid_t_defined
#endif

#ifndef __timer_t_defined
typedef _TIMER_T_ timer_t;
#define __timer_t_defined
#endif

#endif	/* _SYS_TYPES_H */
