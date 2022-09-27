/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:13:36 by jsauvain          #+#    #+#             */
/*   Updated: 2022/09/26 11:39:44 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_die_status(t_thread *thread)
{
	pthread_mutex_lock(&thread->data->mutex_die);
	if (thread->data->die)
	{
		pthread_mutex_unlock(&thread->data->mutex_die);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&thread->data->mutex_die);
		return (0);
	}
}

int	get_meals_status(t_thread *thread)
{
	pthread_mutex_lock(&thread->data->mutex_meals);
	if (thread->data->philo_meals)
	{
		pthread_mutex_unlock(&thread->data->mutex_meals);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&thread->data->mutex_meals);
		return (0);
	}
}
