/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:46:56 by jsauvain          #+#    #+#             */
/*   Updated: 2022/09/29 10:46:29 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	thread_death(t_all *infos, int i)
{
	print_message(&infos->threads[i], "\033[31;01m", "died");
	pthread_mutex_lock(&infos->mutex_die);
	infos->die = 1;
	pthread_mutex_unlock(&infos->mutex_die);
	pthread_mutex_unlock(&infos->mutex_time);
}

void	*check_die(void *arg)
{
	t_all	*infos;
	int		i;

	infos = (t_all *)arg;
	while (get_meals_status(&infos->threads[0])
		&& !get_die_status(&infos->threads[0]))
	{
		i = 0;
		while (i < infos->nb_philos)
		{
			pthread_mutex_lock(&infos->mutex_time);
			if (get_time(infos->threads[i].time) >= infos->to_die)
			{
				thread_death(infos, i);
				return (NULL);
			}
			if (!get_meals_status(&infos->threads[0]))
			{
				pthread_mutex_unlock(&infos->mutex_time);
				return (NULL);
			}
			pthread_mutex_unlock(&infos->mutex_time);
		}
	}
	return (arg);
}
