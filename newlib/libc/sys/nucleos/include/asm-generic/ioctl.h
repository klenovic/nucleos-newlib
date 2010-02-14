/*
 *  Copyright (C) 2009  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
/*	minix/ioctl.h - Ioctl helper definitions.	Author: Kees J. Bot
 *								23 Nov 2002
 *
 * This file is included by every header file that defines ioctl codes.
 */
#ifndef __ASM_GENERIC_IOCTL_H
#define __ASM_GENERIC_IOCTL_H

/* Ioctls have the command encoded in the low-order word, and the size
 * of the parameter in the high-order word. The 3 high bits of the high-
 * order word are used to encode the in/out/void status of the parameter.
 */
#define _IOCPARM_MASK		0x0FFF
#define _IOCPARM_MASK_BIG	0x0FFFFF

#define _IOC_VOID	0x20000000
#define _IOCTYPE_MASK	0xFFFF
#define _IOC_IN		0x40000000
#define _IOC_OUT	0x80000000
#define _IOC_INOUT	(_IOC_IN | _IOC_OUT)

/* Flag indicating ioctl format with only one type field, and more bits
 * for the size field (using mask _IOCPARM_MASK_BIG).
 */
#define _IOC_BIG		0x10000000

#define _IO(x,y)	((x << 8) | y | _IOC_VOID)
#define _IOR(x,y,t)	((x << 8) | y | ((sizeof(t) & _IOCPARM_MASK) << 16) | _IOC_OUT)
#define _IOW(x,y,t)	((x << 8) | y | ((sizeof(t) & _IOCPARM_MASK) << 16) | _IOC_IN)
#define _IORW(x,y,t)	((x << 8) | y | ((sizeof(t) & _IOCPARM_MASK) << 16) | _IOC_INOUT)

#define _IOW_BIG(y,t)	(y | ((sizeof(t) & _IOCPARM_MASK_BIG) << 8) | _IOC_IN | _IOC_BIG)
#define _IOR_BIG(y,t)	(y | ((sizeof(t) & _IOCPARM_MASK_BIG) << 8) | _IOC_OUT | _IOC_BIG)
#define _IORW_BIG(y,t)	(y | ((sizeof(t) & _IOCPARM_MASK_BIG) << 8) | _IOC_INOUT | _IOC_BIG)

/* Decode an ioctl call. */
#define _MINIX_IOCTL_SIZE(i)		(((i) >> 16) & _IOCPARM_MASK)
#define _MINIX_IOCTL_IOR(i)		((i) & _IOC_OUT)
#define _MINIX_IOCTL_IORW(i)		((i) & _IOC_INOUT)
#define _MINIX_IOCTL_IOW(i)		((i) & _IOC_IN)

/* Recognize and decode size of a 'big' ioctl call. */
#define _MINIX_IOCTL_BIG(i) 		((i) & _IOC_BIG)
#define _MINIX_IOCTL_SIZE_BIG(i)	(((i) >> 8) & _IOCPARM_MASK_BIG)


#endif /* __ASM_GENERIC_IOCTL_H */
