/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:39:37 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/05 21:07:48 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(char *msg, t_philo *philo)
{
	unsigned int	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (everyone_alive(philo))
		printf("%u %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->write_lock);
}
