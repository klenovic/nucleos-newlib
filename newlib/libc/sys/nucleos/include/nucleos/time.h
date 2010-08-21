/*
 *  Copyright (C) 2010  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
#ifndef __NUCLEOS_TIME_H
#define __NUCLEOS_TIME_H

#include <nucleos/types.h>

#ifndef _STRUCT_TIMESPEC
#define _STRUCT_TIMESPEC
struct timespec
{
	__kernel_time_t tv_sec;
	long tv_nsec;
};
#endif

struct timeval
{
	long tv_sec;	/*time_t*/
	long tv_usec;	/*useconds_t*/
};

struct timezone {
	int tz_minuteswest;	/* minutes west of Greenwich */
	int tz_dsttime;		/* type of dst correction */
};


/* setitimer/getitimer interface */
struct itimerval
{
	struct timeval it_interval;
	struct timeval it_value;
};

#define ITIMER_REAL	0
#define ITIMER_VIRTUAL	1	/* Not implemented */
#define ITIMER_PROF	2		/* Not implemented */

#define NFDBITS			__NFDBITS

#define FD_SETSIZE		__FD_SETSIZE
#define FD_ZERO(fdsetp)		__FD_ZERO(fdsetp)
#define FD_SET(fd,fdsetp)	__FD_SET(fd,fdsetp)
#define FD_CLR(fd,fdsetp)	__FD_CLR(fd,fdsetp)
#define FD_ISSET(fd,fdsetp)	__FD_ISSET(fd,fdsetp)


#endif /* __NUCLEOS_TIME_H */
