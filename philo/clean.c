/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:37:11 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/28 16:19:07 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_struct(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(data->forks[i]->mut);
		free(data->forks[i]->mut);
		free(data->forks[i]);
		free(data->info[i]->th);
		free(data->info[i]);
		i++;
	}
	free(data->forks[i]->mut);
	free(data->forks);
	free(data->info);
}
