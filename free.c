/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:44:53 by jsauvain          #+#    #+#             */
/*   Updated: 2022/09/22 09:31:55 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_free(t_all *infos, int i)
{
	if (i && infos->threads)
		free(infos->threads);
	if (infos->mutex_forks)
		free(infos->mutex_forks);
	if (infos)
		free(infos);
}
