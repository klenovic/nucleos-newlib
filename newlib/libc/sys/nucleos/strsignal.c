#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <reent.h>

/* Nucleos specific signals. These signals are not used by user proceses,
 * but meant to inform system processes, like the PM, about system events.
 */

static char *sigstring[NSIG] =
  {
    [0] = "Signal 0",
    [SIGHUP] = "Hangup",			/* hangup */
    [SIGINT] = "Interrupt",			/* interrupt (DEL) */
    [SIGQUIT] = "Quit",				/* quit (ASCII FS_PROC_NR) */
    [SIGILL] = "Illegal instruction",		/* illegal instruction */
    [SIGTRAP] = "Trace/breakpoint trap",	/* trace trap (not reset when caught) */
    [SIGABRT] = "IOT trap",			/* IOT instruction */
    [SIGEMT] = "EMT trap",			/* EMT instruction */
    [SIGFPE] = "Floating point exception",	/* floating point exception */
    [SIGKILL] = "Killed",			/* kill (cannot be caught or ignored) */
    [SIGBUS] = "Bus error",			/* bus error */
    [SIGSEGV] = "Segmentation fault",		/* segmentation violation */
//    [] = "Bad system call",
    [SIGPIPE] = "Broken pipe",			/* write on a pipe with no one to read it */
    [SIGALRM] = "Alarm clock",			/* alarm clock */
    [SIGTERM] = "Terminated",			/* software termination signal from kill */
//    [] = "Urgent I/O condition",
    [SIGSTOP] = "Stopped (signal)",		/* stop signal */
    [SIGTSTP] = "Stopped",			/* interactive stop signal */
    [SIGCONT] = "Continued",			/* continue if stopped */
    [SIGCHLD] = "Child exited",			/* child process terminated or stopped */
    [SIGTTIN] = "Stopped (tty input)",		/* background process wants to read */
    [SIGTTOU] = "Stopped (tty output)",		/* background process wants to write */
//    [] = "I/O possible",
//    [] = "CPU time limit exceeded",
//    [] = "File size limit exceeded",
    [SIGVTALRM] = "Virtual timer expired",	/* virtual alarm */
    [SIGPROF] = "Profiling timer expired",	/* profiler alarm */
    [SIGWINCH] = "Window changed",		/* window size has changed */
//    [] = "Resource lost",
    [SIGUSR1] = "User defined signal 1",	/* user defined signal # 1 */
    [SIGUSR2] = "User defined signal 2"		/* user defined signal # 2 */
  };

char *strsignal (int sig)
{
  if (sig < 0 || sig > NSIG)
    {
      char *buffer;
      struct _reent *ptr;

      ptr = _REENT;

      _REENT_CHECK_SIGNAL_BUF(ptr);
      buffer = _REENT_SIGNAL_BUF(ptr);

//      if (sig < 0 || sig > __SIGRTMAX)
        siprintf (buffer, "Unknown signal %d", sig);
/*      else
        siprintf (buffer, "Real-time signal %d", sig - __SIGRTMIN);*/
      return buffer;
    }
  else
    return sigstring[sig];
}
