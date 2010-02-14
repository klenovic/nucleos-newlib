/* libc/sys/linux/include/unistd.h - Various standard functions */

/* Written 2000 by Werner Almesberger */


#ifndef _NEWLIB_UNISTD_H
#define _NEWLIB_UNISTD_H

#include <bits/posix_opt.h>

#include <sys/types.h>
#include <sys/unistd.h>

/* Declare some missing goodies */

extern char *optarg;
extern int optind, opterr, optopt;

/* This value is required by POSIX Table 2-10. */
#define _POSIX_VERSION		199009L  /* which standard is being conformed to */

/* How to exit the system or stop a server process. */
#define RBT_HALT           0    /* shutdown and return to monitor */
#define RBT_REBOOT         1    /* reboot the system through the monitor */
#define RBT_PANIC          2    /* a server panics */
#define RBT_MONITOR        3    /* let the monitor do this */
#define RBT_RESET          4    /* hard reset the system */
#define RBT_INVALID        5    /* first invalid reboot flag */

#endif
