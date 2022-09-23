/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:22:45 by jsauvain          #+#    #+#             */
/*   Updated: 2022/09/23 16:31:39 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	initialize_thread_infos(t_all *infos, char **argv, int i)
{
	infos->threads[i].index = i;
	if (infos->args == 5)
		infos->threads[i].meals = ft_atoi(argv[5]);
	else if (infos->args == 4)
		infos->threads[i].meals = -1;
	infos->threads[i].data = infos;
}

void	init_life_infos(t_all *infos, char **argv, int argc)
{
	infos->die = 0;
	infos->nb_philos = ft_atoi(argv[1]);
	infos->to_die = ft_atoi(argv[2]);
	infos->to_eat = ft_atoi(argv[3]);
	infos->to_sleep = ft_atoi(argv[4]);
	infos->args = argc - 1;
	if (infos->args == 5)
		infos->philo_meals = ft_atoi(argv[1]);
	else if (infos->args == 4)
		infos->philo_meals = -1;
}

void	to_eat(t_thread *thread)
{
	mutex_lock(thread);
	pthread_mutex_lock(&thread->data->mutex_time);
	thread->time = get_time(0);
	pthread_mutex_unlock(&thread->data->mutex_time);
	print_message(thread, "\033[34;01m", "is eating");
	if (thread->data->args == 5)
		thread->meals--;
	if (thread->meals == 0)
	{
		pthread_mutex_lock(&thread->data->mutex_meals);
		thread->data->philo_meals -= 1;
		pthread_mutex_unlock(&thread->data->mutex_meals);
	}
	usleep(thread->data->to_eat * 1000);
	mutex_unlock(thread);
}

void	to_sleep(t_thread *thread)
{
	print_message(thread, "\033[35;01m", "is sleeping");
	usleep(thread->data->to_sleep * 1000);
}

void	to_think(t_thread *thread)
{
	print_message(thread, "\033[37;01m", "is thinking");
}
