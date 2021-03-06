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
#include <signal.h>
#include <errno.h>

int sigprocmask(int how, const sigset_t *set, sigset_t *oldset)
{
	return INLINE_SYSCALL(sigprocmask, 3, how, set, oldset);
}
