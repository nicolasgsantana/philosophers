/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:48:23 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/03 11:52:10 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_valid_char(char c)
{
	return (ft_isdigit(c) || (c == '-' || c == '+'));
}

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!is_valid_char(argv[i][j]))
			{
				ft_putstr_fd(ARGV_ERR, STDERR_FILENO);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
