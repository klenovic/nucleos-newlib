/*
 *  Copyright (C) 2009  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
#ifndef __ASM_GENERIC_POSIX_TYPES_H
#define __ASM_GENERIC_POSIX_TYPES_H

#include <asm/bitsperlong.h>
/*
 * This file is generally used by user-level software, so you need to
 * be a little careful about namespace pollution etc.
 *
 * First the types that are often defined in different ways across
 * architectures, so that you can override them.
 */

#ifndef __kernel_ino_t
typedef unsigned long	__kernel_ino_t;
#endif

#ifndef __kernel_mode_t
typedef unsigned int	__kernel_mode_t;
#endif

#ifndef __kernel_nlink_t
typedef unsigned long	__kernel_nlink_t;
#endif

#ifndef __kernel_pid_t
typedef int		__kernel_pid_t;
#endif

#ifndef __kernel_ipc_pid_t
typedef int		__kernel_ipc_pid_t;
#endif

#ifndef __kernel_uid_t
typedef unsigned int	__kernel_uid_t;
typedef unsigned int	__kernel_gid_t;
#endif

#ifndef __kernel_suseconds_t
typedef long		__kernel_suseconds_t;
#endif

#ifndef __kernel_daddr_t
typedef int		__kernel_daddr_t;
#endif

/*
 * Most 32 bit architectures use "unsigned int" size_t,
 * and all 64 bit architectures use "unsigned long" size_t.
 */
#ifndef __kernel_size_t
#if __BITS_PER_LONG != 64
typedef unsigned int	__kernel_size_t;
typedef int		__kernel_ssize_t;
typedef int		__kernel_ptrdiff_t;
#else
typedef unsigned long	__kernel_size_t;
typedef long		__kernel_ssize_t;
typedef long		__kernel_ptrdiff_t;
#endif
#endif

/*
 * anything below here should be completely generic
 */
typedef long		__kernel_off_t;
typedef long long	__kernel_loff_t;
typedef long		__kernel_time_t;
typedef long		__kernel_clock_t;
typedef int		__kernel_timer_t;
typedef int		__kernel_clockid_t;
typedef char *		__kernel_caddr_t;


#endif /* __ASM_GENERIC_POSIX_TYPES_H */
