/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_sup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:43:02 by jbach             #+#    #+#             */
/*   Updated: 2022/04/21 17:17:05 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

double	ft_diff_time(t_table *table)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000000 + current_time.tv_usec) - \
		(table->sec_time_begin * 1000000 + table->usec_time_begin));
}

int	ft_wait(double time_add)
{
	double			time_goal;
	double			i;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	i = current_time.tv_sec * 1000000 + current_time.tv_usec;
	time_goal = i + time_add;
	while (i < time_goal)
	{
		usleep(time_add);
		i += time_add;
	}
	return (1);
}

struct timeval	ft_time_actual(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time);
}

double	ft_diff_eat(t_philo *philo)
{
	double	timelasteat;
	double	timebegin;

	timelasteat = philo->time_last_eat.tv_sec * 1000000 + \
		philo->time_last_eat.tv_usec;
	timebegin = philo->table->sec_time_begin * 1000000 + \
		philo->table->usec_time_begin;
	return (timelasteat - timebegin);
}
