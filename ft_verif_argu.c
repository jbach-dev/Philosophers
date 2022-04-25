/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_argu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:41:48 by jbach             #+#    #+#             */
/*   Updated: 2022/04/21 17:01:11 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_verif_argu(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 2666)
			return (0);
		else if (ft_atoi(argv[i]) <= 0)
			return (0);
		if (!ft_isnumeric(argv[i]))
			return (0);
		if (ft_atol(argv[i]) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}
