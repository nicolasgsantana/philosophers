/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:48:23 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/04 12:26:45 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	print_error_message(char *error_msg)
{
	ft_putstr_fd(error_msg, STDERR_FILENO);
	return (1);
}

int	check_args(char **argv)
{
	int	error_flag;

	error_flag = 0;
	if ((ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
		|| check_arg(argv[1]))
		error_flag = print_error_message(N_PHILO_ERR);
	if (ft_atoi(argv[2]) <= 0 || check_arg(argv[2]))
		error_flag = print_error_message(DIE_TIME_ERR);
	if (ft_atoi(argv[3]) <= 0 || check_arg(argv[3]))
		error_flag = print_error_message(EAT_TIME_ERR);
	if (ft_atoi(argv[4]) <= 0 || check_arg(argv[4]))
		error_flag = print_error_message(SLEEP_TIME_ERR);
	if (argv[5] && (ft_atoi(argv[5]) <= 0 || check_arg(argv[5])))
		error_flag = print_error_message(EAT_COUNT_ERR);
	return (error_flag);
}
