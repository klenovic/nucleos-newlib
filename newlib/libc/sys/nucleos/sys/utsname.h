#ifndef _SYS_UTSNAME_H
#define _SYS_UTSNAME_H

#define __UTS_LEN	64

struct utsname {
	char sysname[__UTS_LEN + 1];
	char nodename[__UTS_LEN + 1];
	char release[__UTS_LEN + 1];
	char version[__UTS_LEN + 1];
	char machine[__UTS_LEN + 1];
	char domainname[__UTS_LEN + 1];
};

/* Function Prototypes. */
int uname(struct utsname *_name);

#endif /* _SYS_UTSNAME_H */
