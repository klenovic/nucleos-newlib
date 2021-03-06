/* This is a dummy <sys/param.h> file, not customized for any
   particular system.  If there is a param.h in libc/sys/SYSDIR/sys,
   it will override this one.  */

#ifndef _SYS_PARAM_H
# define _SYS_PARAM_H

#include <sys/config.h>
#include <limits.h>
#include <nucleos/limits.h>
#include <nucleos/param.h>
#include <machine/endian.h>
#include <machine/param.h>

#ifndef HZ
# define HZ (100)
#endif
#ifndef NOFILE
# define NOFILE	(60)
#endif
#ifndef PATHSIZE
# define PATHSIZE (1024)
#endif

#ifndef NGROUPS
# define NGROUPS	NGROUPS_MAX
#endif

#define MAXSYMLINKS	16

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#endif
