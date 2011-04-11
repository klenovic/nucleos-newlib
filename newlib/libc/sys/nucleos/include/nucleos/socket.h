/*
 *  Copyright (C) 2011  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
#ifndef __NUCLEOS_SOCKET_H
#define __NUCLEOS_SOCKET_H

/* Can we include <nucleos/types.h> here or do we need an additional header that is
 * safe to include?
 */
#include <nucleos/types.h>

/* Open Group Base Specifications Issue 6 (not complete) */
#include <net/socket.h>

#define SOCK_STREAM	1
#define SOCK_DGRAM	2
#define SOCK_RAW	3
#define SOCK_RDM	4
#define SOCK_SEQPACKET	5

#define SOL_SOCKET	0xFFFF

#define SO_DEBUG	0x0001
#define SO_REUSEADDR	0x0004
#define SO_KEEPALIVE	0x0008
#define SO_TYPE	0x0010	/* get socket type, SOCK_STREAM or SOCK_DGRAM */

#define SO_SNDBUF	0x1001	/* send buffer size */
#define SO_RCVBUF	0x1002	/* receive buffer size */
#define SO_ERROR	0x1007	/* get and clear error status */

/* The how argument to shutdown */
#define SHUT_RD		0	/* No further reads */
#define SHUT_WR		1	/* No further writes */
#define SHUT_RDWR	2	/* No further reads and writes */

typedef uint8_t sa_family_t;

typedef int32_t socklen_t;

struct sockaddr
{
	sa_family_t sa_family;
	char sa_data[8];	/* Big enough for sockaddr_in */
};


/* The following constants are often used in applications, but are not defined
 * by POSIX.
 */
#define PF_UNIX	AF_UNIX
#define PF_INET	AF_INET

#endif /* __NUCLEOS_SOCKET_H */
