#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	run_print_fct(int (*f)(void))
{
	int	bak;
	int	fd;
	int	res;

	fflush(stdout);
	bak = dup(1);
	fd = open("/dev/null", O_WRONLY);
	dup2(fd, 1);
	close(fd);
	res = f();
	fflush(stdout);
	dup2(bak, 1);
	close(bak);
	return (res);
}
