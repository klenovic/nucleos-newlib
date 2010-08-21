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
#include <nucleos/mman.h>
#include <nucleos/errno.h>
#include <machine/syscall.h>
#include <stdarg.h>
#include <sys/errno.h>
#include <sys/types.h>

int munmap(void *addr, size_t len)
{
	return INLINE_SYSCALL(munmap, 2, addr, len);
}
