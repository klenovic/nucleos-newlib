## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = cygnus

INCLUDES = -I$(srcdir)/../include -I$(srcdir)/.. $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)

GENERAL_SOURCES = accept.c ethera2n.c gethnmadr.c getnetent.c getsockname.c inet_network.c \
		  recv.c res_send.c setsockopt.c bind.c ethere2a.c gethostent.c getpeername.c \
		  getsockopt.c inet_ntoa.c recvfrom.c ruserok.c shutdown.c connect.c etherh2n.c \
		  gethostname.c getproto.c getsrvbyname.c listen.c res_comp.c send.c socket.c \
		  dhcp_gettag.c ether_line.c getifaddrs.c getprotoent.c getsrvbyport.c memcspn.c \
		  res_init.c sendto.c strcasecmp.c dhcp_settag.c ethern2h.c getnetbyaddr.c \
		  getprotoname.c hton.c oneC_sum.c res_mkquery.c servxcheck.c domainname.c \
		  getdomain.c getnetbyname.c getservent.c inet_addr.c rcmd.c res_query.c \
		  sethostent.c


ELIX_4_SOURCES =

if ELIX_LEVEL_1
ELIX_SOURCES =
else
if ELIX_LEVEL_2
ELIX_SOURCES =
else
if ELIX_LEVEL_3
ELIX_SOURCES =
else
ELIX_SOURCES = $(ELIX_4_SOURCES)
endif
endif
endif

libnet_la_LDFLAGS = -Xcompiler -nostdlib
#libnet_la_CFLAGS = -DINET6

if USE_LIBTOOL
noinst_LTLIBRARIES = libnet.la
libnet_la_SOURCES = $(GENERAL_SOURCES) $(ELIX_SOURCES)
noinst_DATA = objectlist.awk.in
else
noinst_LIBRARIES = lib.a
lib_a_SOURCES = $(GENERAL_SOURCES) $(ELIX_SOURCES)
lib_a_CFLAGS = $(AM_CFLAGS)
noinst_DATA =
endif # USE_LIBTOOL

include $(srcdir)/../../../../Makefile.shared

install-data-local:
	$(mkinstalldirs) $(DESTDIR)$(tooldir)/include/arpa; \
	for i in $(srcdir)/../include/arpa/*.h; do \
	  $(INSTALL_DATA) $$i $(DESTDIR)$(tooldir)/include/arpa/`basename $$i`; \
	done; \
	$(mkinstalldirs) $(DESTDIR)$(tooldir)/include/net; \
	for i in $(srcdir)/../include/net/*.h; do \
	  $(INSTALL_DATA) $$i $(DESTDIR)$(tooldir)/include/net/`basename $$i`; \
	done; \
	$(mkinstalldirs) $(DESTDIR)$(tooldir)/include/netinet; \
	for i in $(srcdir)/../include/netinet/*.h; do \
	  $(INSTALL_DATA) $$i $(DESTDIR)$(tooldir)/include/netinet/`basename $$i`; \
	done; \
	$(mkinstalldirs) $(DESTDIR)$(tooldir)/include/netinet6; \
	for i in $(srcdir)/../include/netinet6/*.h; do \
	  $(INSTALL_DATA) $$i $(DESTDIR)$(tooldir)/include/netinet6/`basename $$i`; \
	done; \
	$(mkinstalldirs) $(DESTDIR)$(tooldir)/include/netns; \
	for i in $(srcdir)/../include/netns/*.h; do \
	  $(INSTALL_DATA) $$i $(DESTDIR)$(tooldir)/include/netns/`basename $$i`; \
	done; \
	$(mkinstalldirs) $(DESTDIR)$(tooldir)/include/rpc; \
	for i in $(srcdir)/../include/rpc/*.h; do \
	  $(INSTALL_DATA) $$i $(DESTDIR)$(tooldir)/include/rpc/`basename $$i`; \
	done;
