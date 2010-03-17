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

#define __syscall_offset	130
#define NR_syscalls		256	/* number of system calls allowed */

#define __NNR_exit		(1 + __syscall_offset)
#define __NNR_fork		(2 + __syscall_offset)
#define __NNR_read		(3 + __syscall_offset)
#define __NNR_write		(4 + __syscall_offset)
#define __NNR_open		(5 + __syscall_offset)
#define __NNR_close		(6 + __syscall_offset)
#define __NNR_wait		(7 + __syscall_offset)
#define __NNR_creat		(8 + __syscall_offset)
#define __NNR_link		(9 + __syscall_offset)
#define __NNR_unlink		(10 + __syscall_offset)

#define __NNR_waitpid		(11 + __syscall_offset)
#define __NNR_chdir		(12 + __syscall_offset)
#define __NNR_time		(13 + __syscall_offset)
#define __NNR_mknod		(14 + __syscall_offset)
#define __NNR_chmod		(15 + __syscall_offset)
#define __NNR_chown		(16 + __syscall_offset)
#define __NNR_brk		(17 + __syscall_offset)
#define __NNR_stat		(18 + __syscall_offset)
#define __NNR_lseek		(19 + __syscall_offset)
#define __NNR_getpid		(20 + __syscall_offset)

#define __NNR_mount		(21 + __syscall_offset)
#define __NNR_umount		(22 + __syscall_offset)
#define __NNR_setuid		(23 + __syscall_offset)
#define __NNR_getuid		(24 + __syscall_offset)
#define __NNR_stime		(25 + __syscall_offset)
#define __NNR_ptrace		(26 + __syscall_offset)
#define __NNR_alarm		(27 + __syscall_offset)
#define __NNR_fstat		(28 + __syscall_offset)
#define __NNR_pause		(29 + __syscall_offset)
#define __NNR_utime		(30 + __syscall_offset)

#define __NNR_access		(31 + __syscall_offset)
#define __NNR_sync		(32 + __syscall_offset)
#define __NNR_kill		(33 + __syscall_offset)
#define __NNR_rename		(34 + __syscall_offset)
#define __NNR_mkdir		(35 + __syscall_offset)
#define __NNR_rmdir		(36 + __syscall_offset)
#define __NNR_dup		(37 + __syscall_offset)
#define __NNR_pipe		(38 + __syscall_offset)
#define __NNR_times		(39 + __syscall_offset)
#define __NNR_symlink		(40 + __syscall_offset)

#define __NNR_setgid		(41 + __syscall_offset)
#define __NNR_getgid		(42 + __syscall_offset)
#define __NNR_signal		(43 + __syscall_offset)
#define __NNR_readlink		(44 + __syscall_offset)
#define __NNR_lstat		(45 + __syscall_offset)
#define __NNR_ioctl		(46 + __syscall_offset)
#define __NNR_fcntl		(47 + __syscall_offset)
#define __NNR_exec		(48 + __syscall_offset)
#define __NNR_umask		(49 + __syscall_offset)
#define __NNR_chroot		(50 + __syscall_offset)

#define __NNR_setsid		(51 + __syscall_offset)
#define __NNR_getpgrp		(52 + __syscall_offset)
#define __NNR_getitimer		(53 + __syscall_offset)
#define __NNR_setitimer		(54 + __syscall_offset)
/* Posix signal handling. */
#define __NNR_sigaction		(55 + __syscall_offset)
#define __NNR_sigsuspend	(56 + __syscall_offset)
#define __NNR_sigpending	(57 + __syscall_offset)
#define __NNR_sigprocmask	(58 + __syscall_offset)
#define __NNR_sigreturn		(59 + __syscall_offset)
#define __NNR_reboot		(60 + __syscall_offset)

#define __NNR_getdents		(61 + __syscall_offset)
#define __NNR_llseek		(62 + __syscall_offset)
#define __NNR_fstatfs		(63 + __syscall_offset)
#define __NNR_select		(64 + __syscall_offset)
#define __NNR_fchdir		(65 + __syscall_offset)
#define __NNR_fsync		(66 + __syscall_offset)
#define __NNR_getpriority	(67 + __syscall_offset)
#define __NNR_setpriority	(68 + __syscall_offset)
#define __NNR_gettimeofday	(69 + __syscall_offset)
#define __NNR_seteuid		(70 + __syscall_offset)

#define __NNR_setegid		(71 + __syscall_offset)
#define __NNR_truncate		(72 + __syscall_offset)
#define __NNR_ftruncate		(73 + __syscall_offset)
#define __NNR_fchmod		(74 + __syscall_offset)
#define __NNR_fchown		(75 + __syscall_offset)
#define __NNR_sprof		(76 + __syscall_offset)
#define __NNR_cprof		(77 + __syscall_offset)
#define __NNR_getegid		(78 + __syscall_offset)
#define __NNR_getppid		(79 + __syscall_offset)
#define __NNR_dup2		(80 + __syscall_offset)

#define __NNR_uname		(81 + __syscall_offset)
#define __NNR_mmap		(82 + __syscall_offset)
#define __NNR_munmap		(83 + __syscall_offset)
#define __NNR_munmap_text	(84 + __syscall_offset)
#define __NNR_geteuid		(85 + __syscall_offset)
#define __NNR_getgroups		(86 + __syscall_offset)
#define __NNR_setgroups		(87 + __syscall_offset)
#define __NNR_getsysinfo	(88 + __syscall_offset)	/* to PM or FS */
#define __NNR_getsysinfo_up	(89 + __syscall_offset)	/* to PM or FS */
#define __NNR_svrctl		(90 + __syscall_offset)


#endif /* __ASM_X86_UNISTD_32_H */
