/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_print_fct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:45:48 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/25 10:45:50 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	run_print_fct(int (*f)(void))
{
	int	fd_stdout_cpy;
	int	fd_dev_null;
	int	res;

	fflush(stdout);
	fd_stdout_cpy = dup(1);
	if (fd_stdout_cpy == -1)
		return (-1);
	fd_dev_null = open("/dev/null", O_WRONLY);
	if (fd_dev_null == -1)
	{
		close(fd_stdout_cpy);
		return (-1);
	}
	dup2(fd_dev_null, 1);
	close(fd_dev_null);
	res = f();
	fflush(stdout);
	dup2(fd_stdout_cpy, 1);
	close(fd_stdout_cpy);
	return (res);
}
