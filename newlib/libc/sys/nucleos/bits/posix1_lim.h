/* Copyright (C) 1991-1993,96,98,2000-2003,2004 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/*
 *	POSIX Standard: 2.9.2 Minimum Values	Added to <limits.h>
 *
 *	Never include this file directly; use <limits.h> instead.
 */

#ifndef	_BITS_POSIX1_LIM_H
#define	_BITS_POSIX1_LIM_H	1

/* Minimum sizes required by the POSIX P1003.1 standard (Table 2-3). */
#define _POSIX_ARG_MAX		4096  /* exec() may have 4K worth of args */
#define _POSIX_CHILD_MAX	6  /* a process may have 6 children */
#define _POSIX_LINK_MAX		8  /* a file may have 8 links */
#define _POSIX_MAX_CANON	255  /* size of the canonical input queue */
#define _POSIX_MAX_INPUT	255  /* you can type 255 chars ahead */
#define _POSIX_NAME_MAX		60/* max. file name length; @klenovic: the value of DIRSIZ */
#define _POSIX_NGROUPS_MAX	0  /* supplementary group IDs are optional */
#define _POSIX_OPEN_MAX		16  /* a process may have 16 files open */
#define _POSIX_PATH_MAX		255  /* a pathname may contain 255 chars */
#define _POSIX_PIPE_BUF		512  /* pipes writes of 512 bytes must be atomic */
#define _POSIX_STREAM_MAX	8  /* at least 8 FILEs can be open at once */
#define _POSIX_TZNAME_MAX	3  /* time zone names can be at least 3 chars */
#define _POSIX_SSIZE_MAX	32767  /* read() must support 32767 byte reads */
#define _POSIX_SYMLOOP_MAX	8  /* The number of symbolic links that can be
				    * traversed in the resolution of a pathname
				    * in the absence of a loop.
				    */


/* Get the implementation-specific values for the above.  */
#include <bits/local_lim.h>

#ifndef	SSIZE_MAX
# define SSIZE_MAX	LONG_MAX
#endif

/* This value is a guaranteed minimum maximum.
   The current maximum can be got from `sysconf'.  */

#ifndef	NGROUPS_MAX
# define NGROUPS_MAX	8
#endif

#endif	/* bits/posix1_lim.h  */
