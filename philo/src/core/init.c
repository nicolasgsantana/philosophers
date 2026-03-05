/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:51:39 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/05 15:21:36 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_program(t_program *program, t_philo *philos, int philo_num)
{
	program->dead_flag = 0;
	program->philos = philos;
	program->num_of_philos = philo_num;
	if (pthread_mutex_init(&program->write_lock, NULL))
		return (1);
	if (pthread_mutex_init(&program->dead_lock, NULL))
	{
		pthread_mutex_destroy(&program->write_lock);
		return (1);
	}
	if (pthread_mutex_init(&program->meal_lock, NULL))
	{
		pthread_mutex_destroy(&program->write_lock);
		pthread_mutex_destroy(&program->dead_lock);
		return (1);
	}
	return (0);
}

int	init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		if (pthread_mutex_init(&forks[i], NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&forks[i]);
			free(forks);
			return (1);
		}
		i++;
	}
	return (0);
}

void	init_input(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atoui(argv[2]);
	philo->time_to_eat = ft_atoui(argv[3]);
	philo->time_to_sleep = ft_atoui(argv[4]);
	if (argv[5])
		philo->num_times_to_eat = ft_atoi(argv[5]);
	else
		philo->num_times_to_eat = -1;
}

void	init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks,
				char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_input(&philos[i], argv);
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].dead = &program->dead_flag;
		philos[i].r_fork = &forks[i];
		if (i == 0)
			philos[i].l_fork = &forks[program->num_of_philos - 1];
		else
			philos[i].l_fork = &forks[i - 1];
		i++;
	}
}
