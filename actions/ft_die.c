/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:24:32 by jbach             #+#    #+#             */
/*   Updated: 2022/04/21 17:44:42 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_die(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->table->alivemutex) != 0)
		return (0);
	if (philo->table->dead == 0)
	{
		if (pthread_mutex_lock(&philo->table->message) != 0)
			return (pthread_mutex_unlock(&philo->table->alivemutex), 0);
		printf("[%.f] %d %s\n", ft_diff_time(philo->table) / 1000, \
			philo->philo_id, "died");
		if (pthread_mutex_unlock(&philo->table->message) != 0)
			return (pthread_mutex_unlock(&philo->table->alivemutex), 0);
		philo->table->dead = 1;
		if (philo->fork_left == 1 || philo->fork_left == 2)
			if (pthread_mutex_unlock(philo->id_left_fork) != 0)
				return (pthread_mutex_unlock(&philo->table->alivemutex), 0);
		if (philo->fork_right == 1)
			if (pthread_mutex_unlock(philo->id_right_fork) != 0)
				return (pthread_mutex_unlock(&philo->table->alivemutex), 0);
	}
	if (pthread_mutex_unlock(&philo->table->alivemutex) != 0)
		return (0);
	return (1);
}
