/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:32:49 by jsauvain          #+#    #+#             */
/*   Updated: 2022/09/23 16:45:52 by jsauvain         ###   ########.fr       */
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

int	infos_mutex_init(t_all *infos)
{
	int	i;

	i = 0;
	infos->mutex_forks = malloc(infos->nb_philos * sizeof(pthread_mutex_t));
	if (infos->mutex_forks == NULL)
	{
		exit_program(infos);
		return (1);
	}
	while (i < infos->nb_philos)
		pthread_mutex_init(&infos->mutex_forks[i++], NULL);
	pthread_mutex_init(&infos->mutex_time, NULL);
	pthread_mutex_init(&infos->mutex_die, NULL);
	pthread_mutex_init(&infos->mutex_message, NULL);
	pthread_mutex_init(&infos->mutex_meals, NULL);
	return (0);
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
