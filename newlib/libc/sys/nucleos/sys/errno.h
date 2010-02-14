/* errno is not a global variable, because that would make using it
   non-reentrant.  Instead, its address is returned by the function
   __errno.  */

#ifndef _SYS_ERRNO_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _SYS_ERRNO_H_

#include <sys/reent.h>

#ifndef _REENT_ONLY
#define errno (*__errno())
extern int *__errno _PARAMS ((void));
#endif

/* Please don't use these variables directly.
   Use strerror instead. */
extern __IMPORT _CONST char * _CONST _sys_errlist[];
extern __IMPORT int _sys_nerr;
#ifdef __CYGWIN__
extern __IMPORT const char * const sys_errlist[];
extern __IMPORT int sys_nerr;
#endif

#define __errno_r(ptr) ((ptr)->_errno)

/* nucleos */
#include <asm/errno.h>

#define EFTYPE		79	/* Inappropriate file type or format */
#define EILSEQ		84	/* Illegal sequence */
#define EOVERFLOW	139	/* Value too large for defined data type */
#define ECANCELED	140	/* Operation canceled */
#define ENOTRECOVERABLE	141	/* State not recoverable */
#define EOWNERDEAD	142	/* Previous owner died */

#ifdef __cplusplus
}
#endif
#endif /* _SYS_ERRNO_H */
