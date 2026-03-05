/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:14:21 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/05 15:39:05 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_err.h"

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	unsigned int	last_meal;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	start_time;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	int				num_of_philos;
	t_philo			*philos;
}					t_program;

int				ft_atoi(const char *nptr);
unsigned int	ft_atoui(const char *nptr);
void			ft_putstr_fd(char *s, int fd);
int				ft_isdigit(int c);
int				check_args(char **argv);
void			ft_msleep(unsigned int miliseconds);
unsigned int	get_current_time(void);
int				init_program(t_program *program, t_philo *philos, int philo_num);
int				init_forks(pthread_mutex_t *forks, int philo_num);
void			init_input(t_philo *philo, char **argv);
void			init_philos(t_philo *philos, t_program *program,
					pthread_mutex_t *forks, char **argv);

#endif
