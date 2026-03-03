/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:14:21 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/03 11:49:24 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>

# define ARGC_ERR "Error: Incorrect Usage\nUse:\n\
./philo [number of philosophers] \
[time_to_die](ms) [time_to_eat](ms) [time_to_sleep](ms) \
[number_of_times_each_philosopher_must_eat](optional)\n"
# define ARGV_ERR "Error: Args must be numeric\n"

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
void			ft_putstr_fd(char *s, int fd);
int				ft_isdigit(int c);
int				check_args(int argc, char **argv);

#endif
