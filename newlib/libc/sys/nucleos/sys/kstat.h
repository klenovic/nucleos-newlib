/*
 *  Copyright (C) 2009  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
/* The <sys/stat.h> header defines a struct that is used in the stat() and
 * fstat functions.  The information in this struct comes from the i-node of
 * some file.  These calls are the only approved way to inspect i-nodes.
 */

#ifndef __KSTAT_H
#define __KSTAT_H

#include <sys/types.h>
#include <sys/stat.h>

/* @nucleos: This how the current stat looks like in kernel. It neccessary to
	      make a map for now. */
struct kstat {
	dev_t st_dev;		/* major/minor device number */
	ino_t st_ino;		/* i-node number */
	mode_t st_mode;		/* file mode, protection bits, etc. */
	short int st_nlink;	/* # links; TEMPORARY HACK: should be nlink_t*/
	uid_t st_uid;		/* uid of the file's owner */
	short int st_gid;	/* gid; TEMPORARY HACK: should be gid_t */
	dev_t st_rdev;
	off_t st_size;		/* file size */
	time_t st_atime;	/* time of last access */
	time_t st_mtime;	/* time of last data modification */
	time_t st_ctime;	/* time of last file status change */
};

static inline void stat_to_kstat(struct kstat *ks, struct stat *s)
{
	/* @nucleos: we must do this because kernel's `stat' structure differs a bit */
	ks->st_dev = s->st_dev;
	ks->st_ino = s->st_ino;
	ks->st_mode = s->st_mode;
	ks->st_nlink = s->st_nlink;
	ks->st_uid = s->st_uid;
	ks->st_gid = s->st_gid;
	ks->st_rdev = s->st_rdev;
	ks->st_size = s->st_size;
	ks->st_atime = s->st_atime;
	ks->st_mtime = s->st_mtime;
	ks->st_ctime = s->st_ctime;
}

static inline void kstat_to_stat(struct stat *s, struct kstat *ks)
{
	/* @nucleos: we must do this because kernel's `stat' structure differs a bit */
	s->st_dev = ks->st_dev;
	s->st_ino = ks->st_ino;
	s->st_mode = ks->st_mode;
	s->st_nlink = ks->st_nlink;
	s->st_uid = ks->st_uid;
	s->st_gid = ks->st_gid;
	s->st_rdev = ks->st_rdev;
	s->st_size = ks->st_size;
	s->st_atime = ks->st_atime;
	s->st_mtime = ks->st_mtime;
	s->st_ctime = ks->st_ctime;

	/* These below missing in kernel... ugly hardcoded here */
	/* The "preferred" blocksize for efficient file system I/O */
	s->st_blksize = 1024;
	/* Number of blocks allocated to the file, 512-byte units */
	s->st_blocks = ((ks->st_size + 511) >> 9);
}

#endif /* __KSTAT_H */
