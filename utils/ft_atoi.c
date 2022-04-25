/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:42:31 by jbach             #+#    #+#             */
/*   Updated: 2022/04/21 17:07:45 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i])
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while ((str[i] > '/' && str[i] < ':') && str[i] != '\0')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (sign * number);
}
