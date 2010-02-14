/* Definitions of macros to access `dev_t' values.
   Copyright (C) 1996, 1997, 1999 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#ifndef _SYS_SYSMACROS_H
#define _SYS_SYSMACROS_H	1


/* Devices. */
#define MAJOR		8    /* major device = (dev>>MAJOR) & 0377 */
#define MINOR		0    /* minor device = (dev>>MINOR) & 0377 */

#ifndef minor
#define minor(dev)	(((dev) >> MINOR) & 0xff)
#endif

#ifndef major
#define major(dev)	(((dev) >> MAJOR) & 0xff)
#endif

#ifndef makedev
#define makedev(major, minor)	((dev_t) (((major) << MAJOR) | ((minor) << MINOR)))
#endif

#endif /* sys/sysmacros.h */
