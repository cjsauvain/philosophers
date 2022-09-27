/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:32:49 by jsauvain          #+#    #+#             */
/*   Updated: 2022/09/26 11:39:25 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	destroy_mutex(t_all *infos)
{
	int	i;

	i = 0;
	while (i < infos->nb_philos)
		pthread_mutex_destroy(&infos->mutex_forks[i++]);
	pthread_mutex_destroy(&infos->mutex_time);
	pthread_mutex_destroy(&infos->mutex_die);
	pthread_mutex_destroy(&infos->mutex_message);
	pthread_mutex_destroy(&infos->mutex_meals);
}

void	mutex_lock(t_thread *thread)
{
	if (thread->index == thread->data->nb_philos - 1)
	{
		pthread_mutex_lock(&thread->data->mutex_forks[thread->index]);
		print_message(thread, "\033[36;01m", "has taken a fork");
		pthread_mutex_lock(&thread->data->mutex_forks[0]);
		print_message(thread, "\033[36;01m", "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&thread->data->mutex_forks[thread->index]);
		print_message(thread, "\033[36;01m", "has taken a fork");
		pthread_mutex_lock(&thread->data->mutex_forks[thread->index + 1]);
		print_message(thread, "\033[36;01m", "has taken a fork");
	}
}

void	mutex_unlock(t_thread *thread)
{
	if (thread->index == thread->data->nb_philos - 1)
	{
		pthread_mutex_unlock(&thread->data->mutex_forks[thread->index]);
		pthread_mutex_unlock(&thread->data->mutex_forks[0]);
	}
	else
	{
		pthread_mutex_unlock(&thread->data->mutex_forks[thread->index]);
		pthread_mutex_unlock(&thread->data->mutex_forks[thread->index + 1]);
	}
}
