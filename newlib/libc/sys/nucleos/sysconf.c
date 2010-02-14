/*
 *  Copyright (C) 2009  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
/* sysconf.c						POSIX 4.8.1
 *	long int sysconf(int name);
 *
 *	POSIX allows some of the values in <nucleos/limits.h> to be increased at
 *	run time.  The sysconf() function allows such values to be checked
 *	at run time.  MINIX does not use this facility - the run time
 *	limits are those given in <nucleos/limits.h>.
 */
#include <errno.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>
#include <sys/param.h>

long int sysconf(int name)
{
  switch(name) {
	case _SC_ARG_MAX:
		return (long) ARG_MAX;

	case _SC_CHILD_MAX:
		return (long) CHILD_MAX;

	case _SC_CLK_TCK:
		return (long) CLOCKS_PER_SEC;

	case _SC_NGROUPS_MAX:
		return (long) NGROUPS_MAX;

	case _SC_OPEN_MAX:
		return (long) OPEN_MAX;

	case _SC_JOB_CONTROL:
		return -1L;			/* no job control */

	case _SC_SAVED_IDS:
		return -1L;			/* no saved uid/gid */

	case _SC_VERSION:
		return (long) _POSIX_VERSION;

	case _SC_STREAM_MAX:
		return (long) STREAM_MAX;

	case _SC_TZNAME_MAX:
		return (long) TZNAME_MAX;

	case _SC_PAGESIZE:
		return getpagesize();

	default:
		errno = EINVAL;
		return -1L;
  }
}
