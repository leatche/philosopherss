/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:42:07 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/30 13:27:21 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (ft_get_int_value(&philo->timers->stop_m, &philo->timers->stop) == 1)
		return ;
	printf("%ld %d has taken a fork\n", ft_time(philo), philo->id);
	pthread_mutex_lock(philo->left_fork);
	if (ft_get_int_value(&philo->timers->stop_m, &philo->timers->stop) == 1)
		return ;
	printf("%ld %d has taken a fork\n", ft_time(philo), philo->id);
}

void	ft_drop_fork(t_philo *philo)
{
	int	id;

	id = philo->id - 1;
	if (id % 2 == 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

long	ft_time(t_philo *philo)
{
	return (get_time_in_ms() - philo->born_time);
}
