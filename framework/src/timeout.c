/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:56:40 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/25 15:37:24 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libunit.h"
#include <stdio.h>

int	check_time(time_t begin, time_t actual, time_t time_value)
{
	if ((actual - begin) >= time_value)
		return (0);
	return (1);
}

void	*time_process(void *data_void)
{
	time_t	begin;
	int		is_ok;
	t_data	*data;	

	data = (t_data *)data_void;
	begin = time(NULL);
	is_ok = 1;
	while (is_ok == 1)
	{
		if (check_time(begin, time(NULL), TIME_LIMIT) == 0)
			is_ok = 0;
	}
	pthread_mutex_lock(&data->lock);
	if (data->res == NONE)
	{
		data->res = TIMEOUT;
		pthread_cond_signal(&data->cond);
	}
	pthread_mutex_unlock(&data->lock);
	return (NULL);
}

void	*wait_process(void *data_void)
{
	t_data	*data;

	data = (t_data *)data_void;
	wait(data->status);
	pthread_mutex_lock(&data->lock);
	if (data->res == NONE)
	{
		data->res = PROCESS;
		pthread_cond_signal(&data->cond);
	}
	pthread_mutex_unlock(&data->lock);
	return (NULL);
}

void	print_timeout(t_unit_test *test)
{
	ft_printf("%s%s [TIMEOUT]%s\n", RED, test->name, RESET);
}

int	timeout(int *status, pid_t child_pid)
{
	pthread_t			thread1;
	pthread_t			thread2;
	t_data					data;

	data.status = status;
	data.res = NONE;
	pthread_mutex_init(&data.lock, NULL);
	pthread_cond_init(&data.cond, NULL);
	pthread_create(&thread1, NULL, &time_process, &data);
	pthread_create(&thread2, NULL, &wait_process, &data);
	while (data.res == NONE)
		pthread_cond_wait(&data.cond, &data.lock);
	if (data.res == TIMEOUT)
	{
		sigqueue(child_pid, SIGINT, (union sigval)malloc(sizeof(union sigval)));
		pthread_cancel(thread2);
		return (1);
	}
	else 
	{
		pthread_cancel(thread1);
		return (0);
	}
}
