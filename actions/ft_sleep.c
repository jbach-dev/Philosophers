/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:25:00 by jbach             #+#    #+#             */
/*   Updated: 2022/04/21 17:48:01 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_sleep(t_philo *philo)
{
	ft_write(philo, "is sleeping");
	if (ft_wait(philo->table->time_to_sleep) == 0)
		ft_error("Error\nProbleme dans la fonction wait\n", philo->table);
	return (1);
}
