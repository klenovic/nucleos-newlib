#ifdef __cplusplus
extern "C" {
#endif
#include "_ansi.h"
#include <sys/termios.h>

speed_t _EXFUN(cfgetospeed,(const struct termios *__termios_p));
speed_t _EXFUN(cfgetispeed,(const struct termios *__termios_p));
int _EXFUN(cfsetospeed,(struct termios *__termios_p, speed_t __speed));
int _EXFUN(cfsetispeed,(struct termios *__termios_p, speed_t __speed));
int _EXFUN(tcgetattr,(int __fd, struct termios *__termios_p));
int _EXFUN(tcsetattr,(int __fd, int __optional_actions, const struct termios *__termios_p));
int _EXFUN(tcflush,(int fd, int queue_selector));
int _EXFUN(tcdrain,(int fd));
int _EXFUN(tcflow,(int fd, int action));

#ifdef __cplusplus
}
#endif
