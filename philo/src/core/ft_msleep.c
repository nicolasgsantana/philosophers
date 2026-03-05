/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:28:52 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/04 12:04:06 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_msleep(unsigned int miliseconds)
{
	unsigned int	start;

	start = get_current_time();
	while (get_current_time() - start < miliseconds)
		usleep(500);
}
