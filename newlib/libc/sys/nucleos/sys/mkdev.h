#ifndef __MKDEV_H
#define __MKDEV_H

#include <sys/types.h>
#include <_ansi.h>

dev_t _EXFUN(makedev, (major_t, minor_t);
major_t _EXFUN(major, (dev_t));
minor_t _EXFUN(minor, (dev_t dev));

#endif
