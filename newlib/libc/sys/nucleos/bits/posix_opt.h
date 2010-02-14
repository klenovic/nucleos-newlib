/* Define POSIX options for Linux.
   Copyright (C) 1996,1997,1998,1999,2000,2001 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#ifndef	_POSIX_OPT_H
#define	_POSIX_OPT_H	1

/* Job control is supported.  */
#undef	_POSIX_JOB_CONTROL

/* Processes have a saved set-user-ID and a saved set-group-ID.  */
#undef	_POSIX_SAVED_IDS

/* Priority scheduling is supported.  */
#undef	_POSIX_PRIORITY_SCHEDULING

/* Synchronizing file data is supported.  */
#undef	_POSIX_SYNCHRONIZED_IO

/* The fsync function is present.  */
#define	_POSIX_FSYNC	1

/* Mapping of files to memory is supported.  */
#undef	_POSIX_MAPPED_FILES

/* Locking of all memory is supported.  */
#undef	_POSIX_MEMLOCK

/* Locking of ranges of memory is supported.  */
#undef	_POSIX_MEMLOCK_RANGE

/* Setting of memory protections is supported.  */
#undef	_POSIX_MEMORY_PROTECTION

/* Implementation supports `poll' function.  */
#define	_POSIX_POLL	1

/* Implementation supports `select' and `pselect' functions.  */
#define	_POSIX_SELECT	1

/* Only root can change owner of file.  */
#define	_POSIX_CHOWN_RESTRICTED	1

/* `c_cc' member of 'struct termios' structure can be disabled by
   using the value _POSIX_VDISABLE.  */
#undef	_POSIX_VDISABLE

/* Filenames are not silently truncated.  */
#define	_POSIX_NO_TRUNC	1

/* X/Open realtime support is available.  */
#undef _XOPEN_REALTIME

/* X/Open realtime thread support is available.  */
#undef _XOPEN_REALTIME_THREADS

/* XPG4.2 shared memory is supported.  */
#undef	_XOPEN_SHM

/* Tell we have POSIX threads.  */
#undef _POSIX_THREADS

/* We have the reentrant functions described in POSIX.  */
#undef _POSIX_REENTRANT_FUNCTIONS
#undef _POSIX_THREAD_SAFE_FUNCTIONS

/* We provide priority scheduling for threads.  */
#undef	_POSIX_THREAD_PRIORITY_SCHEDULING

/* We support user-defined stack sizes.  */
#undef _POSIX_THREAD_ATTR_STACKSIZE

/* We support user-defined stacks.  */
#undef _POSIX_THREAD_ATTR_STACKADDR

/* We support POSIX.1b semaphores, but only the non-shared form for now.  */
#undef _POSIX_SEMAPHORES

/* Real-time signals are supported.  */
#undef _POSIX_REALTIME_SIGNALS

/* We support asynchronous I/O.  */
#undef _POSIX_ASYNCHRONOUS_IO
#undef _POSIX_ASYNC_IO
/* Alternative name for Unix98.  */
#undef _LFS_ASYNCHRONOUS_IO

/* The LFS support in asynchronous I/O is also available.  */
#undef _LFS64_ASYNCHRONOUS_IO

/* The rest of the LFS is also available.  */
#undef _LFS_LARGEFILE
#undef _LFS64_LARGEFILE
#undef _LFS64_STDIO

/* POSIX shared memory objects are implemented.  */
#undef _POSIX_SHARED_MEMORY_OBJECTS

/* GNU libc provides regular expression handling.  */
#undef _POSIX_REGEXP

/* Reader/Writer locks are available.  */
#undef _POSIX_READER_WRITER_LOCKS

/* We have a POSIX shell.  */
#define _POSIX_SHELL	1

/* We support the Timeouts option.  */
#define _POSIX_TIMEOUTS	200912L

/* We support spinlocks.  */
#undef _POSIX_SPIN_LOCKS

/* The `spawn' function family is supported.  */
#undef _POSIX_SPAWN

/* We have POSIX timers.  */
#define _POSIX_TIMERS	1

/* The barrier functions are available.  */
#undef _POSIX_BARRIERS

/* POSIX message queues are not yet supported.  */
#undef	_POSIX_MESSAGE_PASSING

#endif /* posix_opt.h */
