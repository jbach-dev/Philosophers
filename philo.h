/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <jbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:42:20 by jbach             #+#    #+#             */
/*   Updated: 2022/04/22 10:44:01 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_table	t_table;
typedef struct s_philo
{
	int				philo_id;
	int				nb_eat;
	struct timeval	time_last_eat;
	int				fork_left;
	int				fork_right;
	int				full;
	int				is_eating;
	pthread_mutex_t	*id_left_fork;
	pthread_mutex_t	*id_right_fork;
	pthread_t		id;
	pthread_mutex_t	*alive;
	pthread_mutex_t	tlasteatm;
	pthread_t		supervisor;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	int				nb_philo;
	double			time_to_die;
	double			time_to_eat;
	double			time_to_sleep;
	int				atleast_nb_eat;
	int				nb_full;
	double			sec_time_begin;
	double			usec_time_begin;
	int				dead;
	t_philo			*structphilo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	message;
	pthread_mutex_t	alivemutex;
}	t_table;

int				main(int argc, char **argv);
int				ft_error(char *msg, t_table *table);
int				ft_isdigit(char *c);
int				ft_verif_argu(int argc, char **argv);
int				ft_isnumeric(char *c);
long			ft_atol(const char *str);
t_table			*ft_init_table(char **argv);
int				ft_atoi(const char *str);
int				ft_init_philo(t_table *table);
void			*ft_routine(void *arg);
int				ft_strlen(const char *s);
int				ft_whattime(void);
int				ft_write(t_philo *philo, char *str);
int				ft_close_philo(t_table *table);
int				ft_wait(double time_add);
int				ft_message_mutex(t_table *table);
double			ft_diff_time(t_table *table);
struct	timeval	ft_time_actual(void);
double			ft_diff_eat(t_philo *philo);
int				ft_die(t_philo *philo);
int				ft_eat(t_philo *philo);
int				ft_sleep(t_philo *philo);

#endif
