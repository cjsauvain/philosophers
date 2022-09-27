/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:24:25 by jsauvain          #+#    #+#             */
/*   Updated: 2022/09/26 11:55:04 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_usleep(t_thread *thread, int usleep)
{
	struct timeval	time;
	int				time_0;

	gettimeofday(&time, NULL);
	time_0 = time.tv_sec * 1000 + time.tv_usec / 1000;
	while (get_time(time_0) < usleep && !get_die_status(thread))
		continue;
}

int	get_time(int time_0)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000 - time_0);
}

void	print_message(t_thread *thread, char *color, char *str)
{
	pthread_mutex_lock(&thread->data->mutex_message);
	if (get_meals_status(thread) && !get_die_status(thread))
	{
		printf("%s%d %d %s\033[00m\n",
			color, get_time(thread->data->time), thread->index + 1, str);
	}
	pthread_mutex_unlock(&thread->data->mutex_message);
}

void	exit_program(t_all *infos)
{
	print_error_message("Error : malloc could not be done.\n");
	ft_free(infos, 1);
}
