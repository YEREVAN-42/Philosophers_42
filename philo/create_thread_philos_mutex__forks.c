/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread_philos_mutex__forks.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:28:54 by khovakim          #+#    #+#             */
/*   Updated: 2022/08/19 13:49:47 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	fill_forks_philo(t_main *philos, int i)
{
	int	j;

	if (i == philos->input.philos_count - 1)
		j = 0;
	else
		j = i + 1;
	philos->philo[i].right_fork = &philos->mutex_fork[i];
	philos->philo[i].left_fork = &philos->mutex_fork[j];
}

int	create_philos(t_main *philos)
{
	unsigned long long	create_time;
	int					i;

	philos->philo = malloc(sizeof(t_philo) * (philos->input.philos_count));
	if (philos->philo == NULL)
		return (0);
	i = -1;
	create_time = now();
	while (++i < philos->input.philos_count)
	{
		philos->philo[i].count_eat = 0;
		philos->philo[i].index = i;
		philos->philo[i].input = philos -> input;
		philos->philo[i].time_create = create_time;
		philos->philo[i].write = philos -> write;
		philos->philo[i].time = now();
		fill_forks_philo(philos, i);
	}
	return (1);
}

int	create_mutexes(t_main *philos)
{
	int	i;

	philos->mutex_fork = malloc(sizeof(pthread_mutex_t)
			* (philos->input.philos_count));
	philos->write = malloc(sizeof(pthread_mutex_t));
	if (philos->mutex_fork == NULL || philos->write == NULL)
		return (0);
	pthread_mutex_init(philos->write, NULL);
	i = -1;
	while (++i < philos->input.philos_count)
		if ((pthread_mutex_init(&philos->mutex_fork[i], NULL)) != 0)
			return (0);
	return (1);
}

int	create_threads(t_main *philos)
{
	int	i;

	philos->thread = malloc(sizeof(pthread_t) * philos->input.philos_count);
	if (!philos->thread)
		return (0);
	i = -1;
	while (++i < philos->input.philos_count)
		if ((pthread_create(&philos->thread[i], NULL,
					start_party_for_philo, (void *)&philos->philo[i])) != 0)
			return (0);
	check_party_proces(philos);
	end_party_for_philo(philos);
	return (1);
}
