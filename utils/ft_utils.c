/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:42:54 by jbach             #+#    #+#             */
/*   Updated: 2022/04/21 17:17:48 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	if ((c[i] == '-' || c[i] == '+') && c[1])
		i++;
	while (c[i])
	{
		if (c[i] >= '0' && c[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_isnumeric(char *c)
{
	int	i;

	i = 0;
	if (!ft_isdigit(c) && c[i])
		return (0);
	while (c[i] != '\0')
	{
		if (!ft_isdigit(c))
			return (0);
		i++;
	}
	return (1);
}

int	ft_write(t_philo *philo, char *str)
{
	if (pthread_mutex_lock(philo->alive) != 0)
		return (0);
	if (philo->table->dead == 0)
	{
		if (pthread_mutex_lock(&philo->table->message) != 0)
			return (0);
		printf("[%.f] %d %s\n", ft_diff_time(philo->table) / 1000, \
			philo->philo_id, str);
		if (pthread_mutex_unlock(&philo->table->message) != 0)
			return (0);
	}
	if (pthread_mutex_unlock(philo->alive) != 0)
		return (0);
	return (1);
}
