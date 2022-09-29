/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:58:07 by jsauvain          #+#    #+#             */
/*   Updated: 2022/09/29 10:42:08 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
		thread->data->philo_meals--;
		pthread_mutex_unlock(&thread->data->mutex_meals);
	}
	ft_usleep(thread, thread->data->to_eat);
	mutex_unlock(thread);
}

void	to_sleep(t_thread *thread)
{
	print_message(thread, "\033[35;01m", "is sleeping");
	ft_usleep(thread, thread->data->to_sleep);
}

void	to_think(t_thread *thread)
{
	pthread_mutex_lock(&thread->data->mutex_message);
	if (!get_die_status(thread))
	{
		printf("\033[37;01m%d %d is thinking\033[00m\n",
			get_time(thread->data->time), thread->index + 1);
	}
	pthread_mutex_unlock(&thread->data->mutex_message);
}
