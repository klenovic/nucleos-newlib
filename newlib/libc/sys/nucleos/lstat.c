/*
 *  Copyright (C) 2009  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
#include <nucleos/unistd.h>
#include <nucleos/stat.h>
#include <asm/syscall.h>
#include <sys/errno.h>
#include <sys/kstat.h>

int lstat(const char *path, struct stat *buffer)
{
	int r;
	struct kstat kbuffer;

	if ((r = INLINE_SYSCALL(lstat, 2, path, &kbuffer)) >= 0)
		return r;

	if(r)
		return r;

	kstat_to_stat(buffer, &kbuffer);

	return stat(path, buffer);
}
