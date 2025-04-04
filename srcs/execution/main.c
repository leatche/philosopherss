/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:58:53 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/29 20:14:46 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void one_philo(t_info *info)
{
	printf("0 1 has taken a fork\n");
	usleep(info->timers->t_die * 1000);
	printf("%ld 1 died\n", info->timers->t_die);
}

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac > 4 && ac < 7)
	{
		info = malloc(sizeof(t_info));
		info->timers = malloc(sizeof(t_time));
		if (ft_parsing(ac, av, info) == -1) {
			free(info->timers);
			free(info);
			return (-1);
		}
		info->rooms = malloc(sizeof(pthread_t) * info->nb_philos);
		info->philos = malloc(sizeof(t_philo) * info->nb_philos);
		info->forks = malloc(sizeof(pthread_mutex_t) * info->nb_philos);
		if (ft_check_format(info) == -1 || ft_init_thread(info) == -1)
		{
			ft_free_everything(info);
			ft_error("so that mean that there is a problem !!\n");
			return (-1);
		}
		if (info->nb_philos == 1)
			one_philo(info);
		else {
			ft_start_simulation(info);
			printf("The simulation reach the end ... Good bye !!\n");
		}
		ft_free_everything(info);
	}
	else
		ft_error("the number of argument isn't good at all !!\n");
	return (0);
}
