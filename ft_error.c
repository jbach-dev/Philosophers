/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:18:43 by jbach             #+#    #+#             */
/*   Updated: 2022/04/22 10:43:40 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_error(char *msg, t_table *table)
{
	write(2, msg, ft_strlen(msg));
	if (table != NULL)
	{
		free(table->structphilo);
		free(table->forks);
		free(table);
	}
	return (0);
}
