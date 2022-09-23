/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:16:17 by jsauvain          #+#    #+#             */
/*   Updated: 2022/09/23 16:45:28 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_isdigit(int c, int j)
{
	if (!j && ((c >= '0' && c <= '9') || c == '-'))
		return (1);
	else if (j && (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

long int	ft_atoi(const char *nptr)
{
	int			i;
	long int	nb;

	i = 0;
	nb = 0;
	while (nptr[i])
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	if (nb > 2147483647 || !nb || nptr[0] == '-')
		return (0);
	return (nb);
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
