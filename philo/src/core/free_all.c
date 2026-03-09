/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:04:36 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/09 15:14:48 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_program *program, t_philo *philos, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->num_of_philos)
		pthread_mutex_destroy(&forks[i++]);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
	free(philos);
	free(forks);
}
