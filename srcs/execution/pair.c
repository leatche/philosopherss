/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:41:06 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/31 19:49:15 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_running(t_philo *philo)
{
	return (ft_get_int_value(&philo->timers->stop_m, &philo->timers->stop) == 0);
}

void ft_talk(t_philo *philo, char *msg)
{
	if (!is_running(philo))
		return ;
	printf("%ld %d %s\n", ft_time(philo), philo->id, msg);
}

int ft_get_int_value(pthread_mutex_t *mutex, int *value)
{
	int dest;

	pthread_mutex_lock(mutex);
	dest = *value;
	pthread_mutex_unlock(mutex);
	return (dest);
}

void	*philo_dinner(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (is_running(philo))
	{
		ft_eat(philo);
		ft_sleeping(philo);
	}
	return (NULL);
}

void	ft_eat(t_philo *philo)
{
	ft_take_fork(philo);
	ft_talk(philo, "is eating");
	pthread_mutex_lock(&philo->secure_meal);
	philo->count_meal++;
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->secure_meal);
	ft_usleep(philo, philo->timers->t_eat);
	ft_drop_fork(philo);
}

void	ft_sleeping(t_philo *philo)
{
	ft_talk(philo, "is sleeping");
	ft_usleep(philo, philo->timers->t_sleep);
	ft_talk(philo, "is thinking");
}
