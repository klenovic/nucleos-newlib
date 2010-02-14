/*
 *  Copyright (C) 2009  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
#include <assert.h>
#include <nucleos/errno.h>
#include <stdio.h>
#include <nucleos/string.h>
#include <nucleos/ioctl.h>
#include <nucleos/socket.h>
#include <nucleos/types.h>
#include <netinet/tcp.h>

#include <net/gen/in.h>
#include <net/gen/tcp.h>
#include <net/gen/tcp_io.h>
#include <net/gen/udp.h>
#include <net/gen/udp_io.h>

#include <asm/ioctls.h>

#define DEBUG 0

static int _tcp_getsockopt(int socket, int level, int option_name,
	void *__restrict option_value, socklen_t *__restrict option_len);
static int _udp_getsockopt(int socket, int level, int option_name,
	void *__restrict option_value, socklen_t *__restrict option_len);

int getsockopt(int socket, int level, int option_name,
        void *__restrict option_value, socklen_t *__restrict option_len)
{
	int r;
	nwio_tcpopt_t tcpopt;
	nwio_udpopt_t udpopt;

	r= ioctl(socket, NWIOGTCPOPT, &tcpopt);
	if (r != -1 || errno != ENOTTY)
	{
		if (r == -1)
		{
			/* Bad file descriptor */
			return -1;
		}
		return _tcp_getsockopt(socket, level, option_name,
			option_value, option_len);
	}

	r= ioctl(socket, NWIOGUDPOPT, &udpopt);
	if (r != -1 || errno != ENOTTY)
	{
		if (r == -1)
		{
			/* Bad file descriptor */
			return -1;
		}
		return _udp_getsockopt(socket, level, option_name,
			option_value, option_len);
	}

#if DEBUG
	fprintf(stderr, "getsockopt: not implemented for fd %d\n", socket);
#endif
	errno= ENOTSOCK;
	return -1;
}

static int _tcp_getsockopt(int socket, int level, int option_name,
	void *__restrict option_value, socklen_t *__restrict option_len)
{
	int i, r, err;

	if (level == SOL_SOCKET && option_name == SO_KEEPALIVE)
	{
		i= 1;	/* Keepalive is always on */
		if (*option_len < sizeof(i))
			memcpy(option_value, &i, *option_len);
		else
			memcpy(option_value, &i, sizeof(i));
		*option_len= sizeof(i);
		return 0;
	}
	if (level == SOL_SOCKET && option_name == SO_ERROR)
	{
		r= ioctl(socket, NWIOTCPGERROR, &err);
		if (r != 0)
			return r;
		if (*option_len < sizeof(err))
			memcpy(option_value, &err, *option_len);
		else
			memcpy(option_value, &err, sizeof(err));
		*option_len= sizeof(err);
		return 0;
	}
	if (level == SOL_SOCKET && option_name == SO_RCVBUF)
	{
		i= 32*1024;	/* Receive buffer in the current
				 * implementation
				 */
		if (*option_len < sizeof(i))
			memcpy(option_value, &i, *option_len);
		else
			memcpy(option_value, &i, sizeof(i));
		*option_len= sizeof(i);
		return 0;
	}
	if (level == SOL_SOCKET && option_name == SO_SNDBUF)
	{
		i= 32*1024;	/* Send buffer in the current implementation */
		if (*option_len < sizeof(i))
			memcpy(option_value, &i, *option_len);
		else
			memcpy(option_value, &i, sizeof(i));
		*option_len= sizeof(i);
		return 0;
	}
	if (level == IPPROTO_TCP && option_name == TCP_NODELAY)
	{
		i= 0;	/* nodelay is always off */
		if (*option_len < sizeof(i))
			memcpy(option_value, &i, *option_len);
		else
			memcpy(option_value, &i, sizeof(i));
		*option_len= sizeof(i);
		return 0;
	}
#if DEBUG
	fprintf(stderr, "_tcp_getsocketopt: level %d, name %d\n",
		level, option_name);
#endif

	errno= ENOPROTOOPT;
	return -1;
}

static int _udp_getsockopt(int socket, int level, int option_name,
	void *__restrict option_value, socklen_t *__restrict option_len)
{
	int i;

#if DEBUG
	fprintf(stderr, "_udp_getsocketopt: level %d, name %d\n",
		level, option_name);
#endif

	errno= ENOSYS;
	return -1;
}
