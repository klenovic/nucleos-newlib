## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = cygnus

INCLUDES = -I$(srcdir)/include $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS) $(INCLTDL)

if ELIX_LEVEL_1
argp_dir=
ARGP_LIB=
else
argp_dir=argp
ARGP_LIB=argp/libargp.la
endif

SUBDIRS = machine \
	$(argp_dir) \
	$(EXTRA_SUBDIRS)\
	.
#cmath

SUBLIBS = \
	$(ARGP_LIB) \
	$(EXTRA_SUBLIBS) \
	$(NUCLEOS_MACH_LIB)

#cmath/libcmath.la

GENERAL_SOURCES = \
	access.c \
	alarm.c \
	brk.c \
	chdir.c \
	chmod.c \
	chown.c \
	chroot.c \
	close.c \
	cprofile.c \
	creat.c \
	dup2.c \
	dup.c \
	execl.c \
	execle.c \
	execlp.c \
	execv.c \
	execve.c \
	execvp.c \
	_exit.c \
	fchdir.c \
	fchmod.c \
	fchown.c \
	fcntl.c \
	fork.c \
	fstat.c \
	fstatfs.c \
	fsync.c \
	ftruncate.c \
	getdents.c \
	getegid.c \
	geteuid.c \
	getgid.c \
	getitimer.c \
	getpgrp.c \
	getpid.c \
	getppid.c \
	getpriority.c \
	gettimeofday.c \
	getuid.c \
	ioctl.c \
	kill.c \
	link.c \
	lseek64.c \
	lseek.c \
	lstat.c \
	mkdir.c \
	mknod.c \
	mmap.c \
	mount.c \
	munmap.c \
	munmap_text.c \
	open.c \
	pause.c \
	pipe.c \
	read.c \
	readlink.c \
	reboot.c \
	rename.c \
	rmdir.c \
	select.c \
	setegid.c \
	seteuid.c \
	setgid.c \
	setitimer.c \
	setpriority.c \
	setsid.c \
	setuid.c \
	sigaction.c \
	sigpending.c \
	sigprocmask.c \
	sigreturn.c \
	sigsuspend.c \
	sprofile.c \
	stat.c \
	stime.c \
	symlink.c \
	sync.c \
	time.c \
	times.c \
	truncate.c \
	umask.c \
	umount.c \
	uname.c \
	unlink.c \
	utime.c \
	wait.c \
	waitpid.c \
	write.c \
	poll.c

ELIX_2_SOURCES =

ELIX_3_SOURCES =

ELIX_4_SOURCES =

if ELIX_LEVEL_1
ELIX_SOURCES =
else
if ELIX_LEVEL_2
ELIX_SOURCES = $(ELIX_2_SOURCES)
else
if ELIX_LEVEL_3
ELIX_SOURCES = $(ELIX_2_SOURCES) $(ELIX_3_SOURCES)
else
ELIX_SOURCES = $(ELIX_2_SOURCES) $(ELIX_3_SOURCES) $(ELIX_4_SOURCES)
endif
endif
endif

# This will handle both /usr/src/nucleos-2.4/include/asm/signal.h (in Red Hat Nucleos 7.1)
# and also /usr/src/nucleos/include/asm/signal.h in older versions of Red Hat Nucleos
SIGNAL_H = $(newlib_basedir)/newlib/sys/nucleos/include/asm/signal.h

libnucleos_la_LDFLAGS = -Xcompiler -nostdlib

ADD_OBJS = \
	$(NUCLEOS_MACH_LIB)

if USE_LIBTOOL
noinst_LTLIBRARIES = libnucleos.la
libnucleos_la_SOURCES = $(GENERAL_SOURCES) $(ELIX_SOURCES)
libnucleos_la_LIBADD = $(ADD_OBJS)
libnucleos_la_DEPENDENCIES = $(ADD_OBJS)
LIBC_COMPILE = $(LTCOMPILE)
noinst_DATA = objectlist.awk.in
else
noinst_LIBRARIES = lib.a
lib_a_SOURCES = $(GENERAL_SOURCES) $(ELIX_SOURCES)
lib_a_LIBADD = $(ADD_OBJS)
lib_a_DEPENDENCIES = $(ADD_OBJS)
lib_a_CFLAGS = $(AM_CFLAGS)
LIBC_COMPILE = $(COMPILE)
noinst_DATA =

lib.a:  $(lib_a_OBJECTS)
	rm -f $@
	rm -rf tmp
	mkdir tmp
	cd tmp; \
	for i in $(SUBLIBS); do \
	  $(AR) x ../$$i; \
	done; \
	$(AR) $(AR_FLAGS) ../$@ *.o
	$(RANLIB) $@
	rm -rf tmp

endif # USE_LIBTOOL

objectlist.awk.in: $(noinst_LTLIBRARIES) $(SUBLIBS)
	-rm -f objectlist.awk.in
	for i in `ls *.lo` ; \
	  do \
	    echo $$i `pwd`/$$i >> objectlist.awk.in ; \
	done
	for j in $(SUBLIBS) ; \
	  do \
	    export i=`echo $$j | sed -e 's,\(.*\)\/[^\/]*$$,\1,'`; \
	    if test $$i != "." && test -f $$i/objectlist.awk.in; then \
	    	cat $$i/objectlist.awk.in >> objectlist.awk.in ; \
	    fi; \
	done

all-local: crt0.o

crt0.o: machine/crt0.o
	rm -f $@
	ln machine/crt0.o $@ >/dev/null 2>/dev/null || cp machine/crt0.o $@

machine/crt0.o: ; @true

$(lpfx)sig.$(oext):	siglist.inc

siglist.inc:
		$(AWK) '{ max = 32 } \
		  /#define.SIG.*[1-9][0-9]*/ { n[$$3] = $$2 } \
		  /#define.NSIG.*[1-9][0-9]*/ { max = $$3 } \
		  /#define.SIGUNUSED/ \
		    { for (i = 0; i <= max; i++) print "\"" n[i] "\"," }' \
		    < $(SIGNAL_H) > siglist.inc || \
		    { rm -f siglist.inc; exit 1; }

AM_CFLAGS = -I $(srcdir)/../../stdio
ACLOCAL_AMFLAGS = -I ../../.. -I ../../../..
CONFIG_STATUS_DEPENDENCIES = $(newlib_basedir)/configure.host
