/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:11:24 by jbach             #+#    #+#             */
/*   Updated: 2022/04/21 16:39:26 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc == 5 || argc == 6)
	{		
		if (!ft_verif_argu(argc, argv))
			ft_error("Error\nArguments invalides\n", NULL);
		table = ft_init_table(argv);
		if (!table)
			ft_error("Error\nInitialisation de la table principale\n", NULL);
		table->structphilo = malloc(sizeof(t_philo) * table->nb_philo);
		if (!(table->structphilo))
			return (0);
		if (ft_init_philo(table) == 0)
			ft_error("Error\nInitialisation des philosophers\n", table);
		if (ft_close_philo(table) == 0)
			ft_error("Error\nInitialisation de la fonction close\n", table);
		if (table->nb_full == table->nb_philo)
			printf("%s\n", "La simulation prend fin");
		free(table->structphilo);
		free(table->forks);
		free(table);
	}
	else
		ft_error("Error\nNombre  d'arguments invalides\n", NULL);
}
