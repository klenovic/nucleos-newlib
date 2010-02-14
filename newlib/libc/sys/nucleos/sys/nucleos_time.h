#ifndef _NUCLEOS_TIME_H
#define _NUCLEOS_TIME_H

#include <asm/param.h>
#include <sys/types.h>

#ifndef _STRUCT_TIMESPEC
#define _STRUCT_TIMESPEC
struct timespec {
	time_t	tv_sec;		/* seconds */
	long	tv_nsec;	/* nanoseconds */
};
#endif /* _STRUCT_TIMESPEC */

#ifndef _STRUCT_TIMEVAL
#define _STRUCT_TIMEVAL
struct timeval {
	time_t		tv_sec;		/* seconds */
	suseconds_t	tv_usec;	/* microseconds */
};
#endif

struct timezone {
	int tz_minuteswest;	/* minutes west of Greenwich */
	int tz_dsttime;	/* type of dst correction */
};

#define	ITIMER_REAL	0
#define	ITIMER_VIRTUAL	1
#define	ITIMER_PROF	2

struct  itimerspec {
	struct timespec it_interval;	/* timer period */
	struct timespec it_value;	/* timer expiration */
};

struct itimerval {
	struct timeval it_interval;	/* timer interval */
	struct timeval it_value;	/* current value */
};

#endif /* _NUCLEOS_TIME_H */
