/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:13:39 by nde-sant          #+#    #+#             */
/*   Updated: 2026/02/26 17:00:45 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mssleep(unsigned int ms)
{
	usleep(ms * 1000);
}

int	main(int argc, char **argv)
{
	unsigned int ms;

	ms = 2000;
	if (argc == 5 || argc == 6)
		(void)argv;
	ft_mssleep(ms);
	printf("slept for %d seconds\n", ms / 1000);
	return (0);
}
