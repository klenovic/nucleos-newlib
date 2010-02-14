#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

/**
 * @brief pathconf
 * @param path  name of file being interrogated
 * @param name  property being inspected
 */
long pathconf(const char *path, int name)
{
/* POSIX allows some of the values in <nucleos/limits.h> to be increased at
 * run time.  The pathconf and fpathconf functions allow these values
 * to be checked at run time.  MINIX does not use this facility.
 * The run-time limits are those given in <nucleos/limits.h>.
 */

  int fd;
  long val;

  if ( (fd = open(path, O_RDONLY)) < 0) return(-1L);
  val = fpathconf(fd, name);
  close(fd);
  return(val);
}
