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

#define __NR_exit		(1 + __syscall_offset)
#define __NR_fork		(2 + __syscall_offset)
#define __NR_read		(3 + __syscall_offset)
#define __NR_write		(4 + __syscall_offset)
#define __NR_open		(5 + __syscall_offset)
#define __NR_close		(6 + __syscall_offset)
#define __NR_wait		(7 + __syscall_offset)
#define __NR_creat		(8 + __syscall_offset)
#define __NR_link		(9 + __syscall_offset)
#define __NR_unlink		(10 + __syscall_offset)

#define __NR_waitpid		(11 + __syscall_offset)
#define __NR_chdir		(12 + __syscall_offset)
#define __NR_time		(13 + __syscall_offset)
#define __NR_mknod		(14 + __syscall_offset)
#define __NR_chmod		(15 + __syscall_offset)
#define __NR_chown		(16 + __syscall_offset)
#define __NR_brk		(17 + __syscall_offset)
#define __NR_stat		(18 + __syscall_offset)
#define __NR_lseek		(19 + __syscall_offset)
#define __NR_getpid		(20 + __syscall_offset)

#define __NR_mount		(21 + __syscall_offset)
#define __NR_umount		(22 + __syscall_offset)
#define __NR_setuid		(23 + __syscall_offset)
#define __NR_getuid		(24 + __syscall_offset)
#define __NR_stime		(25 + __syscall_offset)
#define __NR_ptrace		(26 + __syscall_offset)
#define __NR_alarm		(27 + __syscall_offset)
#define __NR_fstat		(28 + __syscall_offset)
#define __NR_pause		(29 + __syscall_offset)
#define __NR_utime		(30 + __syscall_offset)

#define __NR_access		(31 + __syscall_offset)
#define __NR_sync		(32 + __syscall_offset)
#define __NR_kill		(33 + __syscall_offset)
#define __NR_rename		(34 + __syscall_offset)
#define __NR_mkdir		(35 + __syscall_offset)
#define __NR_rmdir		(36 + __syscall_offset)
#define __NR_dup		(37 + __syscall_offset)
#define __NR_pipe		(38 + __syscall_offset)
#define __NR_times		(39 + __syscall_offset)
#define __NR_symlink		(40 + __syscall_offset)

#define __NR_setgid		(41 + __syscall_offset)
#define __NR_getgid		(42 + __syscall_offset)
#define __NR_signal		(43 + __syscall_offset)
#define __NR_readlink		(44 + __syscall_offset)
#define __NR_lstat		(45 + __syscall_offset)
#define __NR_ioctl		(46 + __syscall_offset)
#define __NR_fcntl		(47 + __syscall_offset)
#define __NR_exec		(48 + __syscall_offset)
#define __NR_umask		(49 + __syscall_offset)
#define __NR_chroot		(50 + __syscall_offset)

#define __NR_setsid		(51 + __syscall_offset)
#define __NR_getpgrp		(52 + __syscall_offset)
#define __NR_getitimer		(53 + __syscall_offset)
#define __NR_setitimer		(54 + __syscall_offset)
/* Posix signal handling. */
#define __NR_sigaction		(55 + __syscall_offset)
#define __NR_sigsuspend	(56 + __syscall_offset)
#define __NR_sigpending	(57 + __syscall_offset)
#define __NR_sigprocmask	(58 + __syscall_offset)
#define __NR_sigreturn		(59 + __syscall_offset)
#define __NR_reboot		(60 + __syscall_offset)

#define __NR_getdents		(61 + __syscall_offset)
#define __NR_llseek		(62 + __syscall_offset)
#define __NR_fstatfs		(63 + __syscall_offset)
#define __NR_select		(64 + __syscall_offset)
#define __NR_fchdir		(65 + __syscall_offset)
#define __NR_fsync		(66 + __syscall_offset)
#define __NR_getpriority	(67 + __syscall_offset)
#define __NR_setpriority	(68 + __syscall_offset)
#define __NR_gettimeofday	(69 + __syscall_offset)
#define __NR_seteuid		(70 + __syscall_offset)

#define __NR_setegid		(71 + __syscall_offset)
#define __NR_truncate		(72 + __syscall_offset)
#define __NR_ftruncate		(73 + __syscall_offset)
#define __NR_fchmod		(74 + __syscall_offset)
#define __NR_fchown		(75 + __syscall_offset)
#define __NR_sprof		(76 + __syscall_offset)
#define __NR_cprof		(77 + __syscall_offset)
#define __NR_getegid		(78 + __syscall_offset)
#define __NR_getppid		(79 + __syscall_offset)
#define __NR_dup2		(80 + __syscall_offset)

#define __NR_uname		(81 + __syscall_offset)
#define __NR_mmap		(82 + __syscall_offset)
#define __NR_munmap		(83 + __syscall_offset)
#define __NR_munmap_text	(84 + __syscall_offset)
#define __NR_geteuid		(85 + __syscall_offset)
#define __NR_getgroups		(86 + __syscall_offset)
#define __NR_setgroups		(87 + __syscall_offset)
#define __NR_getsysinfo	(88 + __syscall_offset)	/* to PM or FS */
#define __NR_getsysinfo_up	(89 + __syscall_offset)	/* to PM or FS */
#define __NR_svrctl		(90 + __syscall_offset)


#endif /* __ASM_X86_UNISTD_32_H */
