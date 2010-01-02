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

int fstat(int fd, struct stat *buffer)
{
	int err;
	struct kstat kbuffer;

	err = INLINE_SYSCALL(fstat, 2, fd, &kbuffer);

	if (!err)
		kstat_to_stat(buffer, &kbuffer);

	return err;
}
