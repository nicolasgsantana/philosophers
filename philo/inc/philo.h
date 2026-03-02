/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:14:21 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/02 15:38:34 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_philo
{
	int				count;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	int				times_must_eat;
}	t_philo;

int				ft_atoi(const char *nptr);
unsigned int	ft_atoui(const char *nptr);

#endif
