/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:06:53 by khovakim          #+#    #+#             */
/*   Updated: 2022/08/19 12:38:15 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	all_philos_have_eaten(t_main *philos)
{
	int	i;

	i = -1;
	while (++i < philos->input.philos_count)
		if (philos->input.max_eat == 0
			|| philos->philo[i].count_eat < philos->input.max_eat)
			return (0);
	return (1);
}

static int	someone_died(t_philo *p)
{
	if (now() - p->time > p->input.time_to_die)
		return (1);
	return (0);
}

void	check_party_proces(t_main *philos)
{
	int	i;

	while (1)
	{
		if (all_philos_have_eaten(philos))
		{
			ft_usleep(10);
			printf("%sProces has successfully completed\n", GREEN);
			return ;
		}
		i = -1;
		while (++i < philos->input.philos_count)
		{
			if (someone_died(&philos->philo[i]))
			{
				message(&philos->philo[i], RED, "died\n");
				return ;
			}
		}
	}
}
