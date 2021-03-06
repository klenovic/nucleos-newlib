/*
 *  Copyright (C) 2012  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */

#ifndef _NUCLEOS_TTY_H
#define _NUCLEOS_TTY_H

#include <nucleos/types.h>

#define TTYMAGIC	0xb105

/* A struct that the tty driver can use to pass values to the boot monitor.
 * Currently only the value of the origin of the first vty (console), so the
 * boot monitor can properly display it when panicing (tty isn't scheduled
 * to switch to the first vty). It's written at the end of video memory
 * (video memory base + video memory size - sizeof(struct boot_tty_info).
 */

struct boot_tty_info {
	u16_t	reserved[30];	/* reserved, set to 0 */
	u16_t	consorigin;	/* origin in video memory of console */
	u16_t	conscursor;	/* position of cursor of console */
	u16_t   flags;		/* flags indicating which fields are valid */
	u16_t	magic;		/* magic number indicating struct is valid */
};

#define BTIF_CONSORIGIN	0x01	/* consorigin is set */
#define BTIF_CONSCURSOR	0x02	/* conscursor is set */

#endif /* _NUCLEOS_TTY_H */
