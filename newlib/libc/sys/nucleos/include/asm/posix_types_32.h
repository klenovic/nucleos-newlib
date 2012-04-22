/*
 *  Copyright (C) 2012  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
#ifndef __ASM_X86_POSIX_TYPES_32_H
#define __ASM_X86_POSIX_TYPES_32_H
/*
 * This file is generally used by user-level software, so you need to
 * be a little careful about namespace pollution etc.  Also, we cannot
 * assume GCC is being used.
 */

/* Open Group Base Specifications Issue 6 (not complete) */
typedef long		__kernel_useconds_t;	/* Time in microseconds */

/* Types used in disk, inode, etc. data structures. */
typedef char		__kernel_gid_t;		/* group id */
typedef unsigned long	__kernel_ino_t;		/* i-node number (V3 filesystem) */
typedef unsigned short	__kernel_mode_t;	/* file type and permissions bits */
typedef short		__kernel_nlink_t;	/* number of links to a file */
typedef long		__kernel_off_t;		/* offset within a file */
typedef int		__kernel_pid_t;		/* process id (must be signed) */
typedef short		__kernel_uid_t;		/* user id */

typedef unsigned int	__kernel_size_t;
typedef int 		__kernel_ssize_t;
typedef long 		__kernel_time_t;	/* time in sec since 1 Jan 1970 0000 GMT */
typedef long 		__kernel_clock_t;	/* unit for system accounting */
typedef int		__kernel_daddr_t;
typedef char*		__kernel_caddr_t;
typedef int 		__kernel_ptrdiff_t;

#ifdef __GNUC__
typedef long long	__kernel_loff_t;
#endif

typedef struct {
	int	val[2];
} __kernel_fsid_t;


#endif /* __ASM_X86_POSIX_TYPES_32_H */
