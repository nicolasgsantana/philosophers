/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:13:39 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/05 14:57:49 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	if (argc != 5 && argc != 6)
		return (ft_putstr_fd(ARGC_ERR, STDERR_FILENO), 1);
	if (check_args(argv))
		return (1);
	philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!philos || !forks)
	{
		free(philos);
		free(forks);
		return (ft_putstr_fd(MALLOC_ERR, STDERR_FILENO), 1);
	}
	if (init_program(&program, philos))
		return (ft_putstr_fd(INIT_ERR, STDERR_FILENO), 1);
	if (init_forks(forks, ft_atoi(argv[1])))
		return (ft_putstr_fd(INIT_ERR, STDERR_FILENO), 1);
	init_philos(philos, &program, forks, argv);
	return (0);
}
