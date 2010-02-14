#ifndef _NEWLIB_STDIO_H
#define _NEWLIB_STDIO_H

#include <sys/lock.h>
#include <sys/reent.h>

#if !defined(__SINGLE_THREAD__)
#  if !defined(_flockfile)
#    define _flockfile(fp) flockfile(fp)
#  endif
#  if !defined(_funlockfile)
#    define _funlockfile(fp) funlockfile(fp)
#  endif
#endif /* __SINGLE_THREAD__ */

#define L_ctermid 255   /* required by POSIX */
#define L_cuserid 255   /* required by POSIX */

char *  _EXFUN(ctermid, (char *));

#endif /* _NEWLIB_STDIO_H */
