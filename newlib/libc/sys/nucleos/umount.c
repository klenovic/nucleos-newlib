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
#include <nucleos/string.h>
#include <sys/mount.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <paths.h>
#include <sys/errno.h>
#include <machine/syscall.h>

#define FSPATH "/sbin/"
#define FSDEFAULT "minixfs"

static int rs_down(char *label)
{
	char cmd[200];

	if(strlen(_PATH_SERVICE)+strlen(label)+50 >= sizeof(cmd))
		return -1;
	sprintf(cmd, _PATH_SERVICE " down '%s'", label);
	return system(cmd);
}

static char *makelabel(const char *special)
{
	static char label[40];
	const char *dev;

	/* Make label name. */
	dev = strrchr(special, '/');

	if(dev)
		dev++;
	else
		dev = special;

	if(strchr(dev, '\'') != NULL) {
		errno = EINVAL;
		return NULL;
	}

	if(strlen(dev)+4 >= sizeof(label)) {
		errno = E2BIG;
		return NULL;
	}

	sprintf(label, "fs_%s", dev);
	return label;
}

int umount(const char *target)
{
	char *label;
	int r;

	/* Make MFS process label for RS from special target. */
	if(!(label = makelabel(target))) {
		return -1;
	}

	r = INLINE_SYSCALL(umount, 1, target);

	if (r == 0) {
		rs_down(label);
	}

	return r;
}
