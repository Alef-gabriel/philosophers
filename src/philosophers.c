/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:05:21 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/27 20:33:10 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_eat(t_pthred *args)
{
	pthread_mutex_lock(args->left_fork->mut);
	printf("[%ld] %d has taken a fork\n", time_from_start_in_ms(), args->id);
	pthread_mutex_lock(args->right_fork->mut);
	printf("[%ld] %d has taken a fork\n", time_from_start_in_ms(), args->id);
	args->time_eat = (time_from_start_in_ms() + args->data->time_to_eat + args->data->time_to_sleep + 10);
	args->philo_eat++;
	printf("[%ld] %d is eating\n", time_from_start_in_ms(), args->id);
	usleep(args->data->time_to_eat * 1000);
	pthread_mutex_unlock(args->left_fork->mut);
	pthread_mutex_unlock(args->right_fork->mut);
	return ((void *)args);

}

int	monitoring(t_philo *data)
{
	int	i;
	int	time;
	int	all_philo_death;

	while (1)
	{
		i = 0;
		all_philo_death = 0;
		while (i < data->number_of_philosophers)
		{
			time = (time_from_start_in_ms() - data->info[i]->time_eat) - 10;
			if (data->info[i]->philo_eat && time > data->time_to_die)
			{
				printf("[%ld] %d died time %d and time errado %d\n", time_from_start_in_ms(), data->info[i]->id, data->info[i]->time_eat, time);
				return (1);
			}
			if (data->must_eat != -1 && data->info[i]->philo_eat >= data->must_eat)
			{
				data->info[i]->philo_death = 1;
				all_philo_death++;
			}
			i++;
		}
		if (all_philo_death == i)
			break ;
	}
	return (0);
}

int	start_simulation(t_philo *philo)
{
	int	i;

	i = 0;
	time_from_start_in_ms();
	while (i < philo->number_of_philosophers)
	{
		if (pthread_create(philo->info[i]->th, NULL, &life_philo, philo->info[i]))
			return (1);
		pthread_detach(*(philo->info[i]->th));
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_philo	philo;

	if (checker(argc, argv) == 1)
		return (1);
	//printf("teste = %f\n", 0.0007 * 1000);
	parce(argv, &philo);
	init_fork(&philo);
	philo.info = info_inicialize(&philo);
	start_simulation(&philo);
	monitoring(&philo);
	clear_struct(&philo);
	return (0);
}