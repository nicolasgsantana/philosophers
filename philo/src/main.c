/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:13:39 by nde-sant          #+#    #+#             */
/*   Updated: 2026/03/04 12:31:37 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (ft_putstr_fd(ARGC_ERR, STDERR_FILENO), 1);
	if (check_args(argv))
		return (1);
	return (0);
}
