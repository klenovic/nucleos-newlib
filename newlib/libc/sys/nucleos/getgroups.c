/*
 *  Copyright (C) 2009  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
#include <sys/types.h>
#include <sys/errno.h>
#include <nucleos/unistd.h>
#include <asm/syscall.h>

int getgroups(int gidsetsize, gid_t grouplist[])
{
	return INLINE_SYSCALL(getgroups, 2, gidsetsize, grouplist);
}
