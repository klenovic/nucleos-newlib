/* vi: set sw=4 ts=4: */
/*
 * crypt() for uClibc
 * Copyright (C) 2008 by Erik Andersen <andersen@uclibc.org>
 * Licensed under the LGPL v2.1, see the file COPYING.LIB in this tarball.
 */

#define __FORCE_GLIBC
#include <crypt.h>
#include <unistd.h>
#include <errno.h>
#include "libcrypt.h"

#define __set_errno(val) errno=val

char *crypt(const char *key, const char *salt)
{
	__set_errno(ENOSYS);
	return NULL;
}

void
setkey(const char *key)
{
	__set_errno(ENOSYS);
}

void
encrypt(char *block, int flag)
{
	__set_errno(ENOSYS);
}
