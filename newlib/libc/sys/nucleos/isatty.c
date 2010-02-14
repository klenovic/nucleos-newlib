#include <termios.h>
#include <unistd.h>

int isatty(int fd)
{
	struct termios dummy;

	return(tcgetattr(fd, &dummy) == 0);
}
