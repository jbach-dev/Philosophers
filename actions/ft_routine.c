/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:43:15 by jbach             #+#    #+#             */
/*   Updated: 2022/04/22 12:08:43 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_iflastargv(t_philo *philo)
{
	if (philo->table->atleast_nb_eat != -1)
	{
		if (philo->nb_eat == philo->table->atleast_nb_eat)
		{
			philo->table->nb_full += 1;
			philo->full = 1;
		}
	}
}

void	ft_boucle(t_philo *philo, int alive)
{
	while (alive == 0 && philo->full == 0)
	{
		if (pthread_mutex_lock(&philo->table->alivemutex) != 0)
			ft_error("Error\nProbleme du lock du mutex\n", philo->table);
		alive = philo->table->dead;
		if (pthread_mutex_unlock(&philo->table->alivemutex) != 0)
			ft_error("Error\nProbleme d'unlock du mutex\n", philo->table);
		ft_iflastargv(philo);
		if (pthread_mutex_lock(&philo->tlasteatm) != 0)
			ft_error("Error\nProbleme de lock du mutex\n", philo->table);
		if ((ft_diff_time(philo->table) - ft_diff_eat(philo)) > \
			(philo->table->time_to_die + 2000))
		{
			if (ft_die(philo) == 0)
			{
				pthread_mutex_unlock(&philo->tlasteatm);
				ft_error("Error\nProbleme dans la fonction die", philo->table);
			}
		}
		if (pthread_mutex_unlock(&philo->tlasteatm) != 0)
			ft_error("Error\nProbleme de lock du mutex\n", philo->table);
	}
}

void	*ft_verif_if_alive(void *arg)
{
	t_philo	*philo;
	int		alive;

	philo = (t_philo *) arg;
	if (pthread_mutex_lock(&philo->table->alivemutex) != 0)
		ft_error("Error\nProbleme du lock du mutex\n", philo->table);
	alive = philo->table->dead;
	if (pthread_mutex_unlock(&philo->table->alivemutex) != 0)
		ft_error("Error\nProbleme d'unlock du mutex\n", philo->table);
	ft_boucle(philo, alive);
	return (0);
}

void	ft_routine_spe(t_philo *philo)
{
	if (philo->fork_left == 0 && philo->fork_right == 0)
		if (ft_write(philo, "is thinking") == 0)
			ft_error("Error\nDans la fonction write\n", philo->table);
	if (ft_eat(philo) == 0)
		ft_error("Error\nDans la fonction eat\n", philo->table);
	if (philo->table->nb_philo != 1)
		if (ft_sleep(philo) == 0)
			ft_error("Error\nDans la fonction sleep\n", philo->table);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	int		alive;

	philo = (t_philo *) arg;
	if (pthread_create(&philo->supervisor, NULL, ft_verif_if_alive, philo) != 0)
		ft_error("Error\nProbleme de creation de thread\n", philo->table);
	if (pthread_mutex_lock(&philo->table->alivemutex) != 0)
		ft_error("Error\nProbleme du lock du mutex\n", philo->table);
	alive = philo->table->dead;
	if (pthread_mutex_unlock(&philo->table->alivemutex) != 0)
		ft_error("Error\nProbleme d'unlock du mutex\n", philo->table);
	while (alive == 0 && philo->full == 0 && \
		philo->table->nb_full != philo->table->nb_philo)
	{
		if (pthread_mutex_lock(&philo->table->alivemutex) != 0)
			ft_error("Error\nProbleme du lock du mutex\n", philo->table);
		alive = philo->table->dead;
		if (pthread_mutex_unlock(&philo->table->alivemutex) != 0)
			ft_error("Error\nProbleme d'unlock du mutex\n", philo->table);
		ft_routine_spe(philo);
	}
	return (0);
}
