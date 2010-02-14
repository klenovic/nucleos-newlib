#ifndef _SYS_SIGNAL_H
#define _SYS_SIGNAL_H
#define _SIGNAL_H

#include <sys/types.h>
#include <asm/signal.h>

#define _SIGSET_T
#define _NSIG	NSIG

/* Here are types that are closely associated with signal handling. */
typedef int sig_atomic_t;
typedef __sighandler_t _sig_func_ptr;

/* POSIX and ANSI function prototypes. */
int raise(int _sig);
__sighandler_t signal(int _sig, __sighandler_t _func);

int _EXFUN(kill, (int, int));
int _EXFUN(sigaction, (int, const struct sigaction *, struct sigaction *));
int _EXFUN(sigaddset, (sigset_t *, const int));
int _EXFUN(sigdelset, (sigset_t *, const int));
int _EXFUN(sigismember, (const sigset_t *, int));
int _EXFUN(sigfillset, (sigset_t *));
int _EXFUN(sigemptyset, (sigset_t *));
int _EXFUN(sigpending, (sigset_t *));
int _EXFUN(sigsuspend, (const sigset_t *));
int _EXFUN(sigpause, (int));
int _EXFUN(sigprocmask, (int _how, const sigset_t *_set, sigset_t *_oset));

#ifdef __USE_BSD
/* @nucleos: The size vary on archs so it should not be here! */
#define __sigmask(sig) \
	(((unsigned long) 1) << ((unsigned)((sig) - 1) % (8 * sizeof (unsigned long))))

/* None of the following functions should be used anymore.  They are here
   only for compatibility.  A single word (`int') is not guaranteed to be
   enough to hold a complete signal mask and therefore these functions
   simply do not work in many situations.  Use `sigprocmask' instead.  */

/* Compute mask for signal SIG.  */
# define sigmask(sig)	__sigmask(sig)

/* Block signals in MASK, returning the old mask.  */
extern int sigblock (int __mask) __THROW;

/* Set the mask of blocked signals to MASK, returning the old mask.  */
extern int sigsetmask (int __mask) __THROW;

/* Return currently selected signal mask.  */
extern int siggetmask (void) __THROW __attribute_deprecated__;
#endif /* Use BSD.  */

#if !defined(_POSIX_SOURCE) || defined(__USE_BSD)
extern const char *const sys_siglist[];
typedef __sighandler_t sig_t; /* BSDism */
#endif

#endif /* _SYS_SIGNAL_H */
