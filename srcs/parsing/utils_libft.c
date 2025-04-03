/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:15:17 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/31 21:59:11 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		minus;
	long	result;

	i = 0;
	while (str[i] && !(str[i] >= '0' && str[i] <= '9') && !(str[i] == '-'
			|| str[i] == '+'))
		i++;
	minus = 1;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result > INT_MAX || result < INT_MIN)
		return (0);
	return (result * minus);
}


