/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:06:36 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/11 15:25:05 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= philo->time_to_die
		&& !philo->eating)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

static int	check_death(t_philo *philos, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		if (is_philo_dead(&philos[i]))
		{
			print_action("died", &philos[i]);
			pthread_mutex_lock(philos->dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	has_eaten_enough(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (philo->meals_eaten >= philo->num_times_to_eat
		&& philo->num_times_to_eat != -1)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

static int	check_meals(t_philo *philo, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		if (!has_eaten_enough(&philo[i]))
			return (0);
		i++;
	}
	return (1);
}

void	*watch(void *ptr)
{
	t_program	*program;

	program = (t_program *)ptr;
	while (1)
	{
		if (check_death(program->philos, program->num_of_philos))
			break ;
		if (check_meals(program->philos, program->num_of_philos))
			break ;
	}
	return (NULL);
}
