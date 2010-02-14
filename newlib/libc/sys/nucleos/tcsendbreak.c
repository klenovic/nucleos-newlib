#include <termios.h>
#include <sys/ioctl.h>

int tcsendbreak(int fd, int duration)
{
	return(ioctl(fd, TCSBRK, &duration));
}
