#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <machine/syscall.h>

const char *const sys_siglist[] = {
#include "siglist.inc"
};
