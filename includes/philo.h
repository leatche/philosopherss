/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:51:04 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/03/30 14:06:38 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

typedef struct s_time
{
	long			t_die;
	int				t_eat;
	int				t_sleep;
	int				numb_eat_required;
	int				stop;
	pthread_mutex_t	stop_m;
}		t_time;

typedef struct s_philo
{
	int				id;
	long			born_time;
	int				count_meal;
	long			last_meal;
	pthread_mutex_t	secure_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_time			*timers;
}				t_philo;


typedef struct s_info
{
	t_time			*timers;
	int				nb_philos;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_t		*rooms;
}				t_info;

//execution
int		ft_check_format(t_info *info);
void	ft_executate_everything(t_info *info);
void	ft_start_simulation(t_info *info);
void	ft_init_values(t_info *info);
int		ft_init_thread(t_info *info);
int		ft_create_fork(t_info *info);
int		ft_create_philosopher(t_info *info);
void	ft_assign_forks(t_info *info, int i);
void	ft_take_fork(t_philo *philo);
void	ft_drop_fork(t_philo *philo);
void	*philo_dinner(void *arg);
long	ft_time(t_philo *philo);
long	get_time_in_ms(void);
void	ft_stop_simulation(t_time *timers);
void	ft_free_everything(t_info *info);
void	ft_eat(t_philo *philo);
void	ft_sleeping(t_philo *philo);
void	*ft_check_death(t_info *info);
void	ft_usleep(long mls);
//parsing 
int		ft_parsing(int ac, char **av, t_info *info);
int		ft_check(char **av);
void	ft_give_value(t_info *info, char **av, int ac);
size_t	ft_strlen(const char *src);
void	ft_error(char *s);
long	ft_atoi(const char *str);
int ft_get_int_value(pthread_mutex_t *mutex, int *value);
#endif
