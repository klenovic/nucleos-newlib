/*
 *  Copyright (C) 2009  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
#ifndef __ASM_X86_UNISTD_32_H
#define __ASM_X86_UNISTD_32_H

#define NR_syscalls		256	/* number of system calls allowed */

#define __NR_exit		1
#define __NR_fork		2
#define __NR_read		3
#define __NR_write		4
#define __NR_open		5
#define __NR_close		6
#define __NR_wait		7
#define __NR_creat		8
#define __NR_link		9
#define __NR_unlink		10

#define __NR_waitpid		11
#define __NR_chdir		12
#define __NR_time		13
#define __NR_mknod		14
#define __NR_chmod		15
#define __NR_chown		16
#define __NR_brk		17
#define __NR_stat		18
#define __NR_lseek		19
#define __NR_getpid		20

#define __NR_mount		21
#define __NR_umount		22
#define __NR_setuid		23
#define __NR_getuid		24
#define __NR_stime		25
#define __NR_ptrace		26
#define __NR_alarm		27
#define __NR_fstat		28
#define __NR_pause		29
#define __NR_utime		30

#define __NR_access		31
#define __NR_sync		32
#define __NR_kill		33
#define __NR_rename		34
#define __NR_mkdir		35
#define __NR_rmdir		36
#define __NR_dup		37
#define __NR_pipe		38
#define __NR_times		39
#define __NR_symlink		40

#define __NR_setgid		41
#define __NR_getgid		42
#define __NR_signal		43
#define __NR_readlink		44
#define __NR_lstat		45
#define __NR_ioctl		46
#define __NR_fcntl		47
#define __NR_exec		48
#define __NR_umask		49
#define __NR_chroot		50

#define __NR_setsid		51
#define __NR_getpgrp		52
#define __NR_getitimer		53
#define __NR_setitimer		54
/* Posix signal handling. */
#define __NR_sigaction		55
#define __NR_sigsuspend		56
#define __NR_sigpending		57
#define __NR_sigprocmask	58
#define __NR_sigreturn		59
#define __NR_reboot		60

#define __NR_getdents		61
#define __NR_llseek		62
#define __NR_fstatfs		63
#define __NR_select		64
#define __NR_fchdir		65
#define __NR_fsync		66
#define __NR_getpriority	67
#define __NR_setpriority	68
#define __NR_gettimeofday	69
#define __NR_seteuid		70

#define __NR_setegid		71
#define __NR_truncate		72
#define __NR_ftruncate		73
#define __NR_fchmod		74
#define __NR_fchown		75
#define __NR_sprof		76
#define __NR_cprof		77
#define __NR_getegid		78
#define __NR_getppid		79
#define __NR_dup2		80

#define __NR_uname		81
#define __NR_mmap		82
#define __NR_munmap		83
#define __NR_munmap_text	84
#define __NR_geteuid		85
#define __NR_getgroups		86
#define __NR_setgroups		87
#define __NR_getsysinfo		88	/* to PM or FS */
#define __NR_getsysinfo_up	89	/* to PM or FS */
#define __NR_svrctl		90


#endif /* __ASM_X86_UNISTD_32_H */
