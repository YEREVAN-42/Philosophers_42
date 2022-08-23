/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:33:54 by khovakim          #+#    #+#             */
/*   Updated: 2022/08/19 12:38:15 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_H
# define PHILO_H

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define WHITE	"\033[0;37m"

# include	<unistd.h>
# include	<sys/time.h>
# include	<pthread.h>
# include	<stdlib.h>
# include	<stdio.h>

typedef struct s_input
{
	int					philos_count;
	int					time_to_eat;
	int					time_to_sleep;
	int					max_eat;
	unsigned long long	time_to_die;
}				t_input;

typedef struct s_philo
{
	int					index;
	int					count_eat;

	unsigned long long	time_create;
	unsigned long long	time;

	t_input				input;

	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*write;
}				t_philo;

typedef struct s_main
{
	t_input			input;
	t_philo			*philo;
	pthread_t		*thread;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	*write;
}				t_main;

void				*start_party_for_philo(void *argument);
void				check_party_proces(t_main *philos);
void				end_party_for_philo(t_main *philos);

void				ft_usleep(unsigned long long time);
void				message(t_philo *p, char *color, char *str);

int					create_philos(t_main *philos);
int					create_mutexes(t_main *philos);
int					create_threads(t_main *philos);

unsigned long long	now(void);

#endif
