/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:16:17 by jsauvain          #+#    #+#             */
/*   Updated: 2022/09/29 11:53:22 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c, int j)
{
	if (!j && ((c >= '0' && c <= '9') || c == '-'))
		return (1);
	else if (j && (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

long int	ft_atoi(char *nptr)
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
	if (nb > 2147483647 || ft_strlen(nptr) > 10 || nptr[0] == '-'
		|| (nptr[0] == '0' && nptr[1]))
		return (-1);
	return (nb);
}
