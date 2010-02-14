#include <signal.h>
#include <errno.h>

/* _NSIG is supposed to be the highest signal number plus one.*/

/* Low bit of signal masks. */
#define SIGBIT_0	((sigset_t) 1)

/* Mask of valid signals (0 - (_NSIG-1)). */
#define SIGMASK		((SIGBIT_0 << _NSIG) - 1)

#define sigisvalid(signo) ((unsigned) (signo) < _NSIG)

int sigaddset(sigset_t *set, int signo)
{
	if (!sigisvalid(signo)) {
		errno = EINVAL;
		return -1;
	}

	*set |= SIGBIT_0 << signo;
	return 0;
}

int sigdelset(sigset_t *set, int signo)
{
	if (!sigisvalid(signo)) {
		errno = EINVAL;
		return -1;
	}

	*set &= ~(SIGBIT_0 << signo);

	return 0;
}

int sigemptyset(sigset_t *set)
{
	*set = 0;
	return 0;
}

int sigfillset(sigset_t *set)
{
	*set = SIGMASK;
	return 0;
}

int sigismember(const sigset_t *set, int signo)
{
	if (!sigisvalid(signo)) {
		errno = EINVAL;
		return -1;
	}

	if (*set & (SIGBIT_0 << signo))
		return 1;

	return 0;
}
