#ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

//t_fork pthread_mutex_t	*mut;

typedef struct s_fork{
	int				id;
	pthread_mutex_t	*mut;
}	t_fork;

typedef struct s_philothread{
	pthread_t		*th;
	int				philo_eat;
	int				philo_death;
	t_fork			*left_fork;
	t_fork			*right_fork;
	struct timeval	*eat_time;
	struct s_philosophers	*data;
	int				id;
}	t_pthred;

typedef struct s_philosophers{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				all_philo_death;
	struct timeval	*start;
	t_fork			**forks;
	t_pthred		**info;
}	t_philo;

int	checker_digit(char **argv);

int	checker(int argc, char **argv);

int	ft_atoi(const char *nptr);

int	parce(char **argv, t_philo *st);

long long int	get_time(void);

float time_diff(struct timeval *start);
#endif