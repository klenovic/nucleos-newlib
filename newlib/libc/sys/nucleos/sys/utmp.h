/* The <utmp.h> header is used by init, login, who, etc. */

#ifndef _SYS_UTMP_H
#define _SYS_UTMP_H

#define UTMP_FILE	"/etc/utmp"		/* the user accouting file */
#define WTMP_FILE	"/usr/adm/wtmp"	/* the login history file */
#define BTMP_FILE	"/usr/adm/btmp"	/* the bad-login history file */
#define LASTLOG_FILE	""

#define UT_NAMESIZE	8
#define UT_LINESIZE	12
#define UT_HOSTSIZE	16

struct utmp {
	char ut_user[UT_NAMESIZE];	/* user name */
	char ut_id[4];			/* /etc/inittab ID */
	char ut_line[UT_LINESIZE];	/* terminal name */
	char ut_host[UT_HOSTSIZE];	/* host name, when remote */
	short ut_pid;			/* process id */
	short int ut_type;		/* type of entry */
	long ut_time;			/* login/logout time */
};

#define ut_name		ut_user	/* for compatibility with other systems */

/* Definitions for ut_type. */
#define RUN_LVL		1	/* this is a RUN_LEVEL record */
#define BOOT_TIME	2	/* this is a REBOOT record */
#define OLD_TIME	3
#define NEW_TIME	4
#define INIT_PROCESS	5	/* this process was spawned by INIT */
#define LOGIN_PROCESS	6	/* this is a 'getty' process waiting */
#define USER_PROCESS	7	/* any other user process */
#define DEAD_PROCESS	8	/* this process has died (wtmp only) */

#define RUNLVL_MSG	"run-level %c"
#define BOOT_MSG	"system boot"
#define OTIME_MSG	"old time"
#define TIME_MSG	"new time"

/* --- redundant, from sys/cygwin/sys/utmp.h --- */

struct utmp *_getutline (struct utmp *);
struct utmp *getutent (void);
struct utmp *getutid (struct utmp *);
struct utmp *getutline (struct utmp *);
void endutent (void);
void pututline (struct utmp *);
void setutent (void);
void utmpname (const char *);

#endif /* _SYS_UTMP_H */
