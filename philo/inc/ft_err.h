/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:19:08 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/09 19:50:03 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERR_H
# define FT_ERR_H

# define ARGC_ERR "Error: Incorrect Usage\nUse:\n\
./philo [number_of_philosophers] \
[time_to_die](ms) [time_to_eat](ms) [time_to_sleep](ms) \
[number_of_times_each_philosopher_must_eat](optional)\n"
# define N_PHILO_ERR "Invalid number of philosophers\n"
# define DIE_TIME_ERR "Invalid time to die\n"
# define EAT_TIME_ERR "Invalid time to eat\n"
# define SLEEP_TIME_ERR "Invalid time to sleep\n"
# define EAT_COUNT_ERR "Invalid number of times each philosopher must eat\n"
# define MALLOC_ERR "Failed to allocate memory\n"
# define INIT_ERR "Failed to init mutex\n"
# define THREAD_START_ERR "Failed to start thread\n"
# define THREAD_JOIN_ERR "Failed to join thread\n"

#endif
