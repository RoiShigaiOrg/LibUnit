/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeout.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:52:42 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/25 15:36:32 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	TIMEOUT_H
# define TIMEOUT_H

# include <pthread.h>

# define TIME_LIMIT 5

typedef	enum e_win
{
	NONE,
	TIMEOUT,
	PROCESS
}	t_win;

typedef	union u_val
{
	int		sival_int;
	void	*sival_ptr;
}	t_val;

typedef struct s_data 
{
	pthread_mutex_t	lock;
	pthread_cond_t	cond;
	int			*status;
	t_win		res;
}	t_data;

int	timeout(int *status, pid_t child_pid);

#endif
