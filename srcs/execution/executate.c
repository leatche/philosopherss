/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:02:09 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/31 19:55:52 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_simulation(t_info *info)
{
	int	i;

	i = -1;
	pthread_mutex_init(&info->timers->stop_m, NULL);
	while (++i < info->nb_philos)
		pthread_create(&info->rooms[i], NULL, philo_dinner, &info->philos[i]);
	ft_check_death(info);
	i = -1;
	while (++i < info->nb_philos)
		pthread_join(info->rooms[i], NULL);
}

void	*ft_check_death(t_info *info)
{
	int	i;
	int n_philo;

	while (42)
	{
		i = 0;
		n_philo = 0;
		while (i < info->nb_philos)
		{
			pthread_mutex_lock(&info->philos[i].secure_meal);
			if (get_time_in_ms() - info->philos[i].last_meal > info->timers->t_die)
			{
				ft_stop_simulation(info->timers);
				pthread_mutex_unlock(&info->philos[i].secure_meal);
				printf("%ld %d died\n", ft_time(info->philos + i), info->philos[i].id);
				return (NULL);
			}
			if (info->philos[i].count_meal >= info->timers->numb_eat_required)
				n_philo++;
			pthread_mutex_unlock(&info->philos[i].secure_meal);
			i++;
		}
		if (n_philo == info->nb_philos && info->timers->numb_eat_required != -1)
		{
			ft_stop_simulation(info->timers);
			break ;
		}
	}
	return (NULL);
}
