/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_test_sigpipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:51:00 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:55:54 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	test_sigpipe(void)
{
	char	buf;
	int pipefd[2];

	pipe(pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	read(pipefd[0], &buf, 1);
	return(0);
}
