/*
 *  Copyright (C) 2009  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
/*	execve() - basic program execution call		Author: Kees J. Bot
 *								21 Jan 1994
 */
#include <nucleos/unistd.h>
#include <nucleos/string.h>
#include <nucleos/errno.h>
#include <asm/syscall.h>

/**
 * @nucleos: Change let kernel side setup the stack.
 */
int execve(const char *path, char * const *argv, char * const *envp)
{
	char * const *ap;
	char * const *ep;
	char *frame;
	char **vp;
	char *sp;
	size_t argc;
	size_t frame_size;
	size_t string_off;
	size_t n;
	int ov;

	/* Assumptions: size_t and char *, it's all the same thing. */

	/* Create a stack image that only needs to be patched up slightly
	 * by the kernel to be used for the process to be executed.
	 */

	ov = 0;			/* No overflow yet. */
	frame_size = 0;		/* Size of the new initial stack. */
	string_off = 0;		/* Offset to start of the strings. */
	argc = 0;		/* Argument count. */

	for (ap = argv; *ap != 0; ap++) {
		n = sizeof(*ap) + strlen(*ap) + 1;
		frame_size += n;

		if (frame_size < n) ov = 1;

		string_off += sizeof(*ap);
		argc++;
	}

	for (ep = envp; *ep != 0; ep++) {
		n = sizeof(*ep) + strlen(*ep) + 1;
		frame_size += n;

		if (frame_size < n) ov = 1;

		string_off+= sizeof(*ap);
	}

	/* Add an argument count and two terminating nulls. */
	frame_size += sizeof(argc) + sizeof(*ap) + sizeof(*ep);
	string_off += sizeof(argc) + sizeof(*ap) + sizeof(*ep);

	/* Align. */
	frame_size = (frame_size + sizeof(char *) - 1) & ~(sizeof(char *) - 1);

	/* The party is off if there is an overflow. */
	if (ov || frame_size < 3 * sizeof(char *)) {
		errno= E2BIG;
		return -1;
	}

	/* Allocate space for the stack frame. */
	if ((frame = (char *) sbrk(frame_size)) == (char *) -1) {
		errno = E2BIG;
		return -1;
	}

	/* Set arg count, init pointers to vector and string tables. */
	*(size_t*)frame = argc;
	vp = (char **) (frame + sizeof(argc));
	sp = frame + string_off;

	/* Load the argument vector and strings. */
	for (ap = argv; *ap != 0; ap++) {
		*vp++ = (char *) (sp - frame);
		n = strlen(*ap) + 1;

		memcpy(sp, *ap, n);

		sp += n;
	}

	*vp++ = 0;

	/* Load the environment vector and strings. */
	for (ep = envp; *ep != 0; ep++) {
		*vp++ = (char *) (sp - frame);
		n = strlen(*ep) + 1;

		memcpy(sp, *ep, n);

		sp += n;
	}

	*vp++ = 0;

	/* Padding. */
	while (sp < frame + frame_size) *sp++ = 0;

	INLINE_SYSCALL(exec, 3, path, frame, frame_size);

	/* Failure, return the memory used for the frame and exit. */
	(void) sbrk(-frame_size);

	return -1;
}
