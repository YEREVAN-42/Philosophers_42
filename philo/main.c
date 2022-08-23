/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:32:17 by khovakim          #+#    #+#             */
/*   Updated: 2022/08/19 13:41:13 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static void	free_all(t_main *philos)
{
	free(philos -> philo);
	free(philos -> write);
	free(philos -> thread);
	free(philos -> mutex_fork);
	free(philos);
}

static int	ft_atoi(const char *str)
{
	int	nbr;
	int	n;

	nbr = 0;
	n = 1;
	while (*str == ' ' || *str == '\v' || *str == '\t' || *str == '\f'
		|| *str == '\r' || *str == '\n')
		++str;
	if (*str == '-')
	{
		n = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += *str - '0';
		++str;
	}
	return (n * nbr);
}

static int	philo_fill(int ac, char **av, t_main *philos)
{
	if (ft_atoi(av[1]) <= 0 || (ft_atoi(av[2]) <= 0)
		|| (ft_atoi(av[3])) <= 0 || (ft_atoi(av[4]) <= 0))
		return (0);
	else if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (0);
	philos -> input.philos_count = ft_atoi(av[1]);
	philos -> input.time_to_die = ft_atoi(av[2]);
	philos -> input.time_to_eat = ft_atoi(av[3]);
	philos -> input.time_to_sleep = ft_atoi(av[4]);
	philos -> input.max_eat = 0;
	if (ac == 6)
		philos -> input.max_eat = ft_atoi(av[5]);
	return (1);
}

static t_main	*party_for_philosophers(int ac, char **av)
{
	t_main	*philos;

	philos = (t_main *)malloc(sizeof(t_main));
	if ((philo_fill(ac, av, philos)) == 0)
	{
		printf("%sInvalid input\n", RED);
		free(philos);
		return (NULL);
	}
	if (create_mutexes(philos) == 0 || create_philos(philos) == 0
		|| create_threads(philos) == 0)
	{
		printf("%sMalloc ERROR\n", RED);
		free(philos);
		return (NULL);
	}
	return (philos);
}

int	main(int ac, char **av)
{
	t_main		*philos;

	philos = NULL;
	if (ac < 5 || ac > 6)
	{
		printf("%sInvalid number of arguments\n", RED);
		return (1);
	}
	else
		philos = party_for_philosophers(ac, av);
	if (philos == NULL)
		return (1);
	free_all(philos);
	return (0);
}
