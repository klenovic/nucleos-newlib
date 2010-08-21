/*
 *  Copyright (C) 2010  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
#ifndef __NUCLEOS_SIGNAL_H
#define __NUCLEOS_SIGNAL_H

#include <nucleos/types.h>
#include <asm/signal.h>
#include <asm/siginfo.h>

/* @nucleos: Probably useless since we don't wan't user programs but for now
	     it used for testing. */

/* For the sigset functions, only use the library version with error
 * checking from user programs. System programs need to be able to use
 * nonstanard signals.
 */
int sigaddset(sigset_t *_set, int _sig);
int sigdelset(sigset_t *_set, int _sig);
int sigemptyset(sigset_t *_set);
int sigfillset(sigset_t *_set);
int sigismember(const sigset_t *_set, int _sig);

#endif /* __NUCLEOS_SIGNAL_H */
