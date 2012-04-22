/*
 *  Copyright (C) 2012  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
#ifndef _NUCLEOS_CONST_H
#define _NUCLEOS_CONST_H

/* Some constant macros are used in both assembler and
 * C code.  Therefore we cannot annotate them always with
 * 'UL' and other type specifiers unilaterally.  We
 * use the following macros to deal with this.
 *
 * Similarly, _AT() will cast an expression with a type in C, but
 * leave it unchanged in asm.
 */

#ifdef __ASSEMBLY__
#define _AC(X,Y)	X
#define _AT(T,X)	X
#else
#define __AC(X,Y)	(X##Y)
#define _AC(X,Y)	__AC(X,Y)
#define _AT(T,X)	((T)(X))
#endif


/* Flag bits for i_mode in the inode. */
#define I_TYPE			0170000	/* this field gives inode type */
#define I_SYMBOLIC_LINK		0120000	/* file is a symbolic link */
#define I_REGULAR		0100000	/* regular file, not dir or special */
#define I_BLOCK_SPECIAL		0060000	/* block special file */
#define I_DIRECTORY		0040000	/* file is a directory */
#define I_CHAR_SPECIAL		0020000	/* character special file */
#define I_NAMED_PIPE    0010000	/* named pipe (FIFO) */
#define I_SET_UID_BIT		0004000	/* set effective uid_t on exec */
#define I_SET_GID_BIT		0002000	/* set effective gid_t on exec */
#define I_SET_STCKY_BIT 0001000	/* sticky bit */ 
#define ALL_MODES       0007777	/* all bits for user, group and others */
#define RWX_MODES		0000777	/* mode bits for RWX only */
#define R_BIT			0000004	/* Rwx protection bit */
#define W_BIT			0000002	/* rWx protection bit */
#define X_BIT			0000001	/* rwX protection bit */
#define I_NOT_ALLOC		0000000	/* this inode is free */


#endif /* _NUCLEOS_CONST_H */
