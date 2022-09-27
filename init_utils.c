/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:16:17 by jsauvain          #+#    #+#             */
/*   Updated: 2022/09/26 11:39:04 by jsauvain         ###   ########.fr       */
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
