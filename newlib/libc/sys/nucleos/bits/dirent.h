/*
 *  Copyright (C) 2009  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
/*	dirent.h - Declarations for directory reading routines.
 *							Author: Kees J. Bot
 *								24 Apr 1989
 * 
 * Note: The V7 format directory entries used under Minix must be transformed
 * into a struct dirent with a d_name of at least 15 characters.  Given that
 * we have to transform V7 entries anyhow it is little trouble to let the
 * routines understand the so-called "flex" directory format too.
 */

#ifndef __BITS_DIRENT_H
#define __BITS_DIRENT_H

#include <sys/types.h>

#define MAXNAMLEN	255	/* nucleos: should be sizeof(dirent.d_name)-1 */

struct dirent {		/* Largest entry (8 slots) */
	ino_t		d_ino;		/* I-node number */
	off_t 		d_off;		/* Offset in directory */
	unsigned short	d_reclen;	/* Length of this record */
	char		d_name[256];	/* Null terminated name */
};

#undef _DIRENT_HAVE_D_NAMLEN
#undef _DIRENT_HAVE_D_TYPE
#define _DIRENT_HAVE_D_RECLEN
#define _DIRENT_HAVE_D_OFF

#endif /* __BITS_DIRENT_H */
