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
#include <machine/syscall.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <asm/statfs.h>

int fstatfs(int fd, struct statfs *buffer)
{
	return INLINE_SYSCALL(fstatfs, 2, fd, buffer);
}
