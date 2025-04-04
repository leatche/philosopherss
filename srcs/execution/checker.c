/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:09:55 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/29 20:16:07 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_format(t_info *info)
{
	if (info->timers->numb_eat_required == 0)
	{
		ft_error("your fifth argument is not high enough ");
		return (-1);
	}
	if (info->nb_philos <= 0)
	{
		ft_error("the number of philosophers is not high enough ");
		return (-1);
	}
	return (0);
}
