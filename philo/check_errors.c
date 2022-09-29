/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:05:15 by jsauvain          #+#    #+#             */
/*   Updated: 2022/09/29 11:44:13 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_error_message(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	check_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j], j))
			{
				print_error_message("Error : wrong argument format.\n");
				return (1);
			}
			j++;
		}
		if (((!ft_atoi(argv[i]) || ft_atoi(argv[i]) == -1) && argv[i + 1])
			|| (!argv[i + 1] && ft_atoi(argv[i]) == -1))
		{
			print_error_message("Error : wrong argument value.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_errors(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		print_error_message("Error : wrong number of arguments.\n");
		return (1);
	}
	else if (check_arguments(argc, argv))
		return (1);
	return (0);
}
