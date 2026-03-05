/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:00:31 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/05 16:27:11 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_threads(t_program *program, pthread_t *observer)
{
	int	i;
	int	j;

	if (pthread_create(observer, NULL, &watch, &program->philos))
		return (1);
	i = 0;
	while (i < program->num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &routine, NULL))
		{
			j = 0;
			while (j < i)
				pthread_join(program->philos[j++].thread, NULL);
			pthread_join(*observer, NULL);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	join_threads(t_program *program, pthread_t *observer)
{
	int	i;
	int	return_status;

	return_status = 0;
	i = 0;
	while (i < program->num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL))
			return_status = 1;
		i++;
	}
	if (pthread_join(*observer, NULL))
		return_status = 1;
	return (return_status);
}

int	thread_handler(t_program *program)
{
	pthread_t	observer;

	if (start_threads(program, &observer))
		return (ft_putstr_fd(THREAD_START_ERR, STDERR_FILENO), 1);
	if (join_threads(program, &observer))
		return (ft_putstr_fd(THREAD_JOIN_ERR, STDERR_FILENO), 1);
	return (0);
}
