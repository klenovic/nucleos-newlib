/*
 *  Copyright (C) 2010  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
#ifndef __SERVERS_MFS_TYPE_H
#define __SERVERS_MFS_TYPE_H

#include <nucleos/types.h>
#include <servers/mfs/const.h>

typedef __u32 __kernel_zone_t;	/* zone number */
typedef __u32 __kernel_block_t;	/* block number */
typedef __u16 __kernel_zone1_t;	/* zone number for V1 file systems */

/* Declaration of the V1 inode as it is on the disk (not in core). */
typedef struct {		/* V1.x disk inode */
	__u16 d1_mode;		/* file type, protection, etc. */
	__s16 d1_uid;		/* user id of the file's owner */
	__s32 d1_size;		/* current file size in bytes */
	__s32 d1_mtime;		/* when was file data last changed */
	__u8 d1_gid;		/* group number */
	__u8 d1_nlinks;		/* how many links to this file */
	__u16 d1_zone[V1_NR_TZONES];	/* block nums for direct, ind, and dbl ind */
} d1_inode;

/* Declaration of the V2 inode as it is on the disk (not in core). */
typedef struct {		/* V2.x disk inode */
	__u16 d2_mode;		/* file type, protection, etc. */
	__u16 d2_nlinks;	/* how many links to this file. HACK! */
	__s16 d2_uid;		/* user id of the file's owner. */
	__u16 d2_gid;		/* group number HACK! */
	__s32 d2_size;		/* current file size in bytes */
	__s32 d2_atime;		/* when was file data last accessed */
	__s32 d2_mtime;		/* when was file data last changed */
	__s32 d2_ctime;		/* when was inode data last changed */
	__u32 d2_zone[V2_NR_TZONES];	/* block nums for direct, ind, and dbl ind */
} d2_inode;


#endif /* __SERVERS_MFS_TYPE_H */
