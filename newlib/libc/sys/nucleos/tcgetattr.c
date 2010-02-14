/*
 *  Copyright (C) 2009  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
#include <sys/ioctl.h>
#include <errno.h>
#include <termios.h>

int tcgetattr(int fd, struct termios *termios_p)
{
	return(ioctl(fd, TCGETS, termios_p));
}
