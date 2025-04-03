/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:44:03 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/30 14:04:51 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_stop_simulation(t_time *timers)
{
	pthread_mutex_lock(&timers->stop_m);
	timers->stop = 1;
	pthread_mutex_unlock(&timers->stop_m);
}

void	ft_free_everything(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philos)
	{
		pthread_mutex_destroy(&info->forks[i]);
		pthread_mutex_destroy(&info->philos[i].secure_meal);
		i++;
	}
	pthread_mutex_destroy(&info->timers->stop_m);
	free(info->forks);
	free(info->philos);
	free(info->timers);
	free(info->rooms);
	free(info);
}

void	ft_usleep(long mls)
{
	int	a;

	a = -1;
	while (++a < 10)
		usleep(mls);
}
