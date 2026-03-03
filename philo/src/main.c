/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:13:39 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/03 11:49:53 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mssleep(unsigned int ms)
{
	usleep(ms * 1000);
}

void	init_philo(t_philo *philo, int argc, char **argv)
{
	int	times_must_eat;

	philo->count = ft_atoi(argv[1]);
	philo->time_die = ft_atoui(argv[2]);
	philo->time_eat = ft_atoui(argv[3]);
	philo->time_sleep = ft_atoui(argv[4]);
	if (argc == 6)
	{
		times_must_eat = ft_atoi(argv[5]);
		if (times_must_eat > 0)
			philo->times_must_eat = times_must_eat;
		else
			philo->times_must_eat = 0;
	}
	else
		philo->times_must_eat = 0;
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc == 5 || argc == 6)
	{
		if (check_args(argc, argv))
			return (1);
		init_philo(&philo, argc, argv);
		printf("Number of philosophers = %d\n", philo.count);
		printf("Time do die in ms = %u\n", philo.time_die);
		printf("Time to eat in ms = %u\n", philo.time_eat);
		printf("Time to sleep in ms = %u\n", philo.time_sleep);
		printf("Number of times the philosophers must eat = %d\n", philo.times_must_eat);
		return (0);
	}
	else
	{
		ft_putstr_fd(ARGC_ERR, STDERR_FILENO);
		return (1);
	}
}
