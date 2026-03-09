/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:37:21 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/09 16:24:11 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think(t_philo *philo)
{
	print_action("is thinking", philo);
}

static void	nap(t_philo *philo)
{
	print_action("is sleeping", philo);
	ft_msleep(philo->time_to_sleep);
}

static void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_msleep(1);
	pthread_mutex_lock(philo->r_fork);
	print_action("has taken a fork", philo);
	if (philo->l_fork == philo->r_fork)
	{
		ft_msleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_action("has taken a fork", philo);
	philo->eating = 1;
	print_action("is eating", philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_msleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (everyone_alive(philo))
	{
		eat(philo);
		pthread_mutex_lock(philo->meal_lock);
		if (philo->meals_eaten >= philo->num_times_to_eat)
		{
			pthread_mutex_unlock(philo->meal_lock);
			break ;
		}
		pthread_mutex_unlock(philo->meal_lock);
		nap(philo);
		think(philo);
	}
	return (NULL);
}
