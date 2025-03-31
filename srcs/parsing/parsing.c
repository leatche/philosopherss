/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:16:28 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/29 20:15:30 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parsing(int ac, char **av, t_info *info)
{
	if (ft_check(av) == -1)
	{
		ft_error("the values have to be positifs integers !\n");
		return (-1);
	}
	ft_give_value(info, av, ac);
	return (0);
}

int	ft_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

void	ft_give_value(t_info *info, char **av, int ac)
{
	info->nb_philos = atoi(av[1]);
	info->timers->t_die = atoi(av[2]);
	info->timers->t_eat = atoi(av[3]);
	info->timers->t_sleep = atoi(av[4]);
	if (ac == 6)
		info->timers->numb_eat_required = atoi(av[5]);
	else
		info->timers->numb_eat_required = -1;
}
