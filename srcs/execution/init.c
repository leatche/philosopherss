/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:57:55 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/31 19:58:11 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_thread(t_info *info)
{
	if (ft_create_fork(info) == -1)
	{
		ft_error("the forks didn't create themselves ");
		return (-1);
	}
	if (ft_create_philosopher(info) == -1)
	{
		ft_error("the philosophers didn't create themselves ");
		return (-1);
	}
	return (0);
}

int	ft_create_fork(t_info *info)
{
	int	i;

	if (!info->forks)
		return (-1);
	i = -1;
	while (++i < info->nb_philos)
		pthread_mutex_init(&(info->forks[i]), NULL);
	return (0);
}

int	ft_create_philosopher(t_info *info)
{
	int	i;

	if (!info->philos)
		return (-1);
	i = -1;
	while (++i < info->nb_philos)
	{
		info->philos[i].id = i + 1;
		info->philos[i].born_time = get_time_in_ms();
		info->philos[i].count_meal = 0;
		info->philos[i].last_meal = info->philos->born_time;
		pthread_mutex_init(&info->philos[i].secure_meal, NULL);
		info->philos[i].timers = info->timers;
		ft_assign_forks(info, i);
	}
	return (0);
}

void	ft_assign_forks(t_info *info, int i)
{
	if (i % 2 == 0)
	{
		info->philos[i].right_fork = &info->forks[i];
		info->philos[i].left_fork = &info->forks[(i + 1) % info->nb_philos];
	}
	else
	{
		info->philos[i].right_fork = &info->forks[(i + 1) % info->nb_philos];
		info->philos[i].left_fork = &info->forks[i];
	}
}
