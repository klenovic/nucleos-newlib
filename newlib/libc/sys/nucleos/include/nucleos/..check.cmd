cmd_/home/devel/tmp/git/nucleos/usr/include/nucleos/.check := for f in auxvec.h binfmts.h com.h const.h elf.h endpoint.h errno.h fcntl.h fs.h ioctl.h kernel.h limits.h magic.h mman.h param.h partition.h posix_types.h resource.h signal.h socket.h stat.h stddef.h string.h swab.h sysinfo.h termios.h time.h times.h tty.h types.h unistd.h utime.h utsname.h wait.h version.h; do echo "/home/devel/tmp/git/nucleos/usr/include/nucleos/$${f}"; done | xargs perl scripts/headers_check.pl /home/devel/tmp/git/nucleos/usr/include x86; touch /home/devel/tmp/git/nucleos/usr/include/nucleos/.check
