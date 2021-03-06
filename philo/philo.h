/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:00:41 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/31 20:52:45 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_fork{
	int				id;
	pthread_mutex_t	*mut;
}	t_fork;

typedef struct s_philothread{
	pthread_t				*th;
	int						philo_eat;
	int						philo_death;
	t_fork					*left_fork;
	t_fork					*right_fork;
	unsigned int			time_eat;
	struct s_philosophers	*data;
	int						id;
}	t_pthred;

typedef struct s_philosophers{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				all_philo_death;
	t_fork			**forks;
	t_pthred		**info;
}	t_philo;

int				checker_digit(char **argv);

int				checker(int argc, char **argv);

int				ft_atoi(const char *nptr);

int				parce(char **argv, t_philo *st);

t_pthred		**info_inicialize(t_philo *data);

void			init_fork(t_philo *data);

void			*life_philo(void *args);

void			*philo_eat(t_pthred *args);

void			clear_struct(t_philo *data);

unsigned long	time_from_start_in_ms(void);
#endif