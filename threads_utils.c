/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:48:31 by jsauvain          #+#    #+#             */
/*   Updated: 2022/09/27 09:31:51 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*start_routine(void *arg)
{
	t_thread	*thread;

	thread = (t_thread *)arg;
	pthread_mutex_lock(&thread->data->mutex_time);
	thread->time = get_time(0);
	pthread_mutex_unlock(&thread->data->mutex_time);
	while (!get_die_status(thread) && get_meals_status(thread))
	{
		to_eat(thread);
		to_sleep(thread);
		to_think(thread);
	}
	return (arg);
}

void	one_philo(t_all *infos)
{
	printf("\033[36;01m%d 1 has taken a fork\n", get_time(infos->time));
	usleep(infos->to_die * 1000);
	printf("\033[31;01m%d 1 died\n", get_time(infos->time));
}

int	many_philos(t_all *infos, char **argv)
{
	pthread_t	thread_die;
	int			i;

	i = 0;
	infos->threads = malloc(infos->nb_philos * sizeof(t_thread));
	if (infos->threads == NULL)
	{
		destroy_mutex(infos);
		exit_program(infos);
		return (1);
	}
	while (i < infos->nb_philos)
	{
		initialize_thread_infos(infos, argv, i);
		pthread_create(&infos->threads[i].philo, NULL,
			start_routine, (void *)&infos->threads[i]);
		usleep(100);
		i++;
	}
	pthread_create(&thread_die, NULL, check_die, (void *)infos);
	i = 0;
	while (i < infos->nb_philos)
		pthread_join(infos->threads[i++].philo, NULL);
	pthread_join(thread_die, NULL);
	return (0);
}

int	thread_init(t_all *infos, char **argv)
{
	if (ft_atoi(argv[1]) == 1)
		one_philo(infos);
	else
	{
		if (many_philos(infos, argv))
			return (1);
	}
	return (0);
}
