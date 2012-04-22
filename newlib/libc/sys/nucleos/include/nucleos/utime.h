/*
 *  Copyright (C) 2012  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
/* The <nucleos/utime.h> header is used for the utime() system call. */

#ifndef _NUCLEOS_UTIME_H
#define _NUCLEOS_UTIME_H

#include <nucleos/types.h>

struct utimbuf {
	__kernel_time_t actime;		/* access time */
	__kernel_time_t modtime;	/* modification time */
};


#endif /* _NUCLEOS_UTIME_H */
