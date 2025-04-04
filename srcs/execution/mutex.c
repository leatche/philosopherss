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
	ft_talk(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	ft_talk(philo, "has taken a fork");
}

void	ft_drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

long	ft_time(t_philo *philo)
{
	return (get_time_in_ms() - philo->born_time);
}
