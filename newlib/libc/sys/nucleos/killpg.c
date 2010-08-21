#include <sys/signal.h>
#include <nucleos/unistd.h>
#include <machine/syscall.h>

/**
 * @brief killpg
 * @param pgrp  which process group is to be sent the signal
 * @param sig  signal number
 */
int killpg(int pgrp, int sig)
{
	return kill(-pgrp, sig);
}
