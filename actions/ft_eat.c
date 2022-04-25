/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:24:41 by jbach             #+#    #+#             */
/*   Updated: 2022/04/22 12:06:51 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_release(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->id_left_fork) != 0)
		return (0);
	philo->fork_left = 0;
	if (pthread_mutex_unlock(philo->id_right_fork) != 0)
		return (0);
	philo->fork_right = 0;
	return (1);
}

int	ft_twoforkslock(t_philo *philo)
{
	if (philo->fork_left == 1 && philo->fork_right == 1)
	{
		ft_write(philo, "is eating");
		philo->is_eating = 1;
		if (pthread_mutex_lock(&philo->tlasteatm) != 0)
			return (0);
		philo->time_last_eat = ft_time_actual();
		if (pthread_mutex_unlock(&philo->tlasteatm) != 0)
			return (0);
		if (ft_wait(philo->table->time_to_eat) == 0)
			return (0);
		if (ft_release(philo) == 0)
			return (0);
		philo->is_eating = 0;
		philo->nb_eat += 1;
	}
	return (1);
}

int	ft_eat(t_philo *philo)
{
	if (philo->nb_eat == 0 && (philo->philo_id % 2 == 1))
		usleep(4000);
	if (philo->fork_left != 2)
	{
		if (pthread_mutex_lock(philo->id_left_fork) == 0)
		{
			ft_write(philo, "has taken a fork");
			philo->fork_left = 1;
			if (philo->table->nb_philo == 1)
				philo->fork_left = 2;
			if (philo->fork_left == 1 && \
				pthread_mutex_lock(philo->id_right_fork) == 0)
			{
				ft_write(philo, "has taken a fork");
				philo->fork_right = 1;
			}
		}
	}
	if (ft_twoforkslock(philo) == 0)
		return (0);
	return (1);
}
