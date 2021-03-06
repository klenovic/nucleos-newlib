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
#include <sys/stat.h>
#include <machine/syscall.h>
#include <sys/errno.h>
#include <sys/types.h>

int mkdir(const char *name, mode_t mode)
{
	return INLINE_SYSCALL(mkdir, 2, name, mode);
}
