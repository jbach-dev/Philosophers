/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:41:30 by jbach             #+#    #+#             */
/*   Updated: 2022/04/21 16:53:28 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_ifpair(t_table *table, int i)
{
	if (i % 2 == 0)
	{
		if (table->structphilo[i].philo_id == 1)
			table->structphilo[i].id_right_fork = \
				&table->forks[table->nb_philo - 1];
		else
			table->structphilo[i].id_right_fork = &table->forks[i - 1];
		table->structphilo[i].id_left_fork = &table->forks[i];
	}
	else
	{
		table->structphilo[i].id_left_fork = &table->forks[i - 1];
		table->structphilo[i].id_right_fork = &table->forks[i];
	}
	if (pthread_create(&table->structphilo[i].id, NULL,
			ft_routine, &table->structphilo[i]) != 0)
		return (0);
	return (1);
}

int	ft_init_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		table->structphilo[i].alive = &table->alivemutex;
		if (pthread_mutex_init(&table->structphilo[i].tlasteatm, NULL) != 0)
			return (0);
		table->structphilo[i].philo_id = i + 1;
		table->structphilo[i].nb_eat = 0;
		table->structphilo[i].fork_left = 0;
		table->structphilo[i].fork_right = 0;
		table->structphilo[i].full = 0;
		if (pthread_mutex_lock(&table->structphilo[i].tlasteatm) != 0)
			return (0);
		table->structphilo[i].time_last_eat = ft_time_actual();
		if (pthread_mutex_unlock(&table->structphilo[i].tlasteatm) != 0)
			return (0);
		table->structphilo[i].is_eating = 0;
		table->structphilo[i].table = table;
		if (ft_ifpair(table, i) == 0)
			return (0);
		i++;
	}
	return (1);
}
