#ifndef _SYS_RESOURCE_H
#define _SYS_RESOURCE_H

#include <sys/time.h>
#include <bits/resource.h>

int getpriority(int, int);
int setpriority(int, int, int);

#define RLIM_SAVED_CUR RLIM_INFINITY
#define RLIM_SAVED_MAX RLIM_INFINITY

int getrlimit(int resource, struct rlimit *rlp);

#endif
