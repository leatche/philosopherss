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

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac > 4 && ac < 7)
	{
		info = malloc(sizeof(t_info));
		info->timers = malloc(sizeof(t_time));
		if (ft_parsing(ac, av, info) == -1)
			return (-1);
		ft_executate_everything(info);
		ft_free_everything(info);
	}
	else
		ft_error("the number of argument isn't good at all !!\n");
	return (0);
}
