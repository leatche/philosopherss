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

void	ft_executate_everything(t_info *info)
{
	if (ft_check_format(info) == -1 || ft_init_thread(info) == -1)
	{
		ft_error("so that mean that there is a problem !!\n");
		return ;
	}
	ft_start_simulation(info);
	printf("The simulation reach the end ... Good bye !!\n");
}

void	ft_start_simulation(t_info *info)
{
	int	i;

	i = -1;
	ft_init_values(info);
	info->rooms = malloc(sizeof(pthread_t) * info->nb_philos);
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

	i = 0;
	info->philos[i].last_meal = info->philos->born_time;
	while (i < info->nb_philos)
	{
		while (i < info->nb_philos)
		{
			if (get_time_in_ms() - info->philos[i].last_meal >= info->timers->t_die)
			{
				ft_stop_simulation(info->timers);
				return (NULL);
			}
			else
				i++;
		}
		i = 0;
	}
	return (NULL);
}
