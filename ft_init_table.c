/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:41:36 by jbach             #+#    #+#             */
/*   Updated: 2022/04/21 17:00:18 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*ft_init_mutex(t_table table)
{
	int				i;
	pthread_mutex_t	*mutex;

	i = 0;
	mutex = malloc(sizeof(pthread_mutex_t) * table.nb_philo);
	if (!mutex)
		ft_error("Error\nProbleme de malloc\n", &table);
	while (i < table.nb_philo)
	{
		if (pthread_mutex_init(&mutex[i], NULL) != 0)
			ft_error("Error\nd'initiatlisation de mutex\n", &table);
		i++;
	}
	return (mutex);
}

int	ft_arguinit(t_table *table, char **argv)
{
	table->nb_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]) * 1000;
	table->time_to_eat = ft_atoi(argv[3]) * 1000;
	table->time_to_sleep = ft_atoi(argv[4]) * 1000;
	table->nb_full = 0;
	table->dead = 0;
	if (argv[5])
	{
		table->atleast_nb_eat = ft_atoi(argv[5]);
		if (table->atleast_nb_eat == 0)
			table->nb_full = table->nb_philo;
	}
	else
		table->atleast_nb_eat = -1;
	return (1);
}

t_table	*ft_init_table(char **argv)
{
	t_table			*table;
	struct timeval	current_time;

	table = malloc(sizeof(t_table));
	if (!table)
		ft_error("Error\nProbleme de malloc\n", table);
	gettimeofday(&current_time, NULL);
	table->sec_time_begin = current_time.tv_sec;
	table->usec_time_begin = current_time.tv_usec;
	ft_arguinit(table, argv);
	table->forks = ft_init_mutex(*table);
	if (pthread_mutex_init(&table->alivemutex, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&table->message, NULL) != 0)
		return (NULL);
	return (table);
}
