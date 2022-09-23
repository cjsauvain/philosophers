/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:04:16 by jsauvain          #+#    #+#             */
/*   Updated: 2022/09/23 16:59:01 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_all			*infos;
	struct timeval	time_0;

	gettimeofday(&time_0, NULL);
	if (check_errors(argc, argv))
		return (0);
	infos = malloc(sizeof(t_all));
	if (infos == NULL)
	{
		exit_program(infos);
		return (0);
	}
	infos->threads = NULL;
	infos->time = time_0.tv_sec * 1000 + time_0.tv_usec / 1000;
	init_life_infos(infos, argv, argc);
	if (infos_mutex_init(infos))
		return (0);
	if (thread_init(infos, argv))
		return (0);
	destroy_mutex(infos);
	if (ft_atoi(argv[1]) != 1)
		ft_free(infos, 1);
	else
		ft_free(infos, 0);
}
