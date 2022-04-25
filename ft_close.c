/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:41:04 by jbach             #+#    #+#             */
/*   Updated: 2022/04/21 16:44:09 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_close_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_join(table->structphilo[i].id, NULL) != 0)
			return (0);
		if (pthread_join(table->structphilo[i].supervisor, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
