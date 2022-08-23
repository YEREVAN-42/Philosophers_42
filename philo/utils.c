/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:06:57 by khovakim          #+#    #+#             */
/*   Updated: 2022/08/19 13:39:38 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec * 0.001);
}

//	kamel senc	//	bayc avelilava usleep ov
//
//	usleep(time * 1000);

void	ft_usleep(unsigned long long time)
{
	unsigned long long	start;

	start = now();
	while (now() - start <= time)
		;
}

void	message(t_philo *p, char *color, char *str)
{
	pthread_mutex_lock(p -> write);
	printf("%s%llu\t%d\t%s", color, now() - p->time_create, p->index + 1, str);
	if (str[0] != 'd')
		pthread_mutex_unlock(p -> write);
}

void	end_party_for_philo(t_main *philos)
{
	int	i;

	i = -1;
	while (++i < philos->input.philos_count)
		pthread_detach(philos->thread[i]);
	i = -1;
	while (++i < philos->input.philos_count)
	{
		pthread_mutex_destroy(&philos->mutex_fork[i]);
		pthread_mutex_destroy(philos->philo[i].write);
		pthread_mutex_destroy(philos->philo[i].right_fork);
		pthread_mutex_destroy(philos->philo[i].left_fork);
	}
	pthread_mutex_destroy(philos->write);
}
