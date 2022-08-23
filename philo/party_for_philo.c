/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   party_for_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:30:51 by khovakim          #+#    #+#             */
/*   Updated: 2022/08/19 12:45:28 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_philo *p);

static void	sleep_think(t_philo *p)
{
	message(p, WHITE, "is sleeping\n");
	ft_usleep(p -> input.time_to_sleep);
	message(p, YELLOW, "is thinking\n");
	eating(p);
}

static void	put_down_forks(t_philo *p)
{
	pthread_mutex_unlock(p -> left_fork);
	pthread_mutex_unlock(p -> right_fork);
}

static void	take_forks(t_philo *p)
{
	pthread_mutex_lock(p -> right_fork);
	message(p, GREEN, "hes taken a fork\n");
	pthread_mutex_lock(p -> left_fork);
	message(p, GREEN, "hes taken a fork\n");
}

static void	eating(t_philo *p)
{
	take_forks(p);
	message(p, BLUE, "is eating\n");
	ft_usleep(p -> input.time_to_eat);
	p -> time = now();
	p -> count_eat++;
	put_down_forks(p);
	sleep_think(p);
}

void	*start_party_for_philo(void *argument)
{
	t_philo	*p;

	p = (t_philo *)argument;
	p -> time = now();
	if ((p -> index & 1) == 1)
		ft_usleep(p->input.time_to_eat);
	eating(p);
	return (NULL);
}
