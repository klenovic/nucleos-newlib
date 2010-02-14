#ifndef __UCONTEXT_H
#define __UCONTEXT_H

#include <signal.h>

struct regs {
	unsigned int gs;
	unsigned int fs;
	unsigned int es;
	unsigned int ds;
	unsigned int edi;
	unsigned int esi;
	unsigned int ebp;
	unsigned int esp;
	unsigned int ebx;
	unsigned int edx;
	unsigned int ecx;
	unsigned int eax;
	unsigned int int_no;
	unsigned int err_code;    /* our 'push byte #' and ecodes do this */
	unsigned int eip;
	unsigned int cs;
	unsigned int eflags;
	unsigned int useresp;
	unsigned int ss;   /* pushed by the processor automatically */
	unsigned int v_es; /* V86 mode only */
	unsigned int v_ds; /* V86 mode only */
	unsigned int v_fs; /* V86 mode only */
	unsigned int v_gs; /* V86 mode only */
};

typedef struct regs mcontext_t;

typedef struct __ucontext_t{
  struct __ucontext_t *uc_link;
  sigset_t    uc_sigmask;
  stack_t     uc_stack;
  mcontext_t  uc_mcontext;
} ucontext_t;

#endif
