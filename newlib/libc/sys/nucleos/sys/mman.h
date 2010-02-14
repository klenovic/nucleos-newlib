/*
 *  Copyright (C) 2009  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */

#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H

#include <asm/mman.h>

void _EXFUN(*mmap,(void *, size_t, int, int, int, off_t));
int _EXFUN(munmap,(void *, size_t));

#endif /* __NUCLEOS_MMAN_H */
