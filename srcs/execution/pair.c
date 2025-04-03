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
	long	now;

	philo = (t_philo *)arg;
	while (!(ft_get_int_value(&philo->timers->stop_m, &philo->timers->stop) == 1))
	{
		ft_eat(philo);
		if (philo->count_meal == philo->timers->numb_eat_required)
		{
			ft_stop_simulation(philo->timers);
			break;
		}
		ft_sleeping(philo);
	}
	now = get_time_in_ms() - philo->born_time;
	printf("%ld %d died\n", now, philo->id);
	return (NULL);
}

void	ft_eat(t_philo *philo)
{
	ft_take_fork(philo);
	pthread_mutex_lock(&philo->secure_meal);
	philo->count_meal++;
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->secure_meal);
	if (ft_get_int_value(&philo->timers->stop_m, &philo->timers->stop) == 1)
		return ;
	printf("%ld %d is eating\n", ft_time(philo), philo->id);
	ft_usleep(philo->timers->t_eat * 100);
	ft_drop_fork(philo);
}

void	ft_sleeping(t_philo *philo)
{
	if (ft_get_int_value(&philo->timers->stop_m, &philo->timers->stop) == 1)
		return ;
	printf("%ld %d is sleeping\n", ft_time(philo), philo->id);
	ft_usleep(philo->timers->t_sleep * 100);
	printf("%ld %d is thinking\n", ft_time(philo), philo->id);
}
