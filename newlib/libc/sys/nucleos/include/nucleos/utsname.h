/*
 *  Copyright (C) 2011  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
#ifndef __NUCLEOS_UTSNAME_H
#define __NUCLEOS_UTSNAME_H

#define __UTS_LEN	64

struct utsname {
	char sysname[__UTS_LEN + 1];
	char nodename[__UTS_LEN + 1];
	char release[__UTS_LEN + 1];
	char version[__UTS_LEN + 1];
	char machine[__UTS_LEN + 1];
	char domainname[__UTS_LEN + 1];
};


#endif /* __NUCLEOS_UTSNAME_H */
