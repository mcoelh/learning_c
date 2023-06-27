/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:26:36 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/03/13 22:54:33 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				max_philo;
	unsigned long	die;
	unsigned long	eat;
	unsigned long	sleep;
	int				x_eat;
	int				satisfied;
	unsigned long	time_start;
	int				*forks;
	int				dead;
	pthread_t		*philos;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print;
	pthread_mutex_t	doctor;
	pthread_mutex_t	dinner;
	pthread_mutex_t	stf;
	struct s_philo	*people;
}				t_data;

typedef struct s_philo
{
	int				id;
	int				max_p;
	int				own_fork;
	int				friend_fork;
	unsigned long	last_meal;
	int				times_eat;
	int				in_hand;
	t_data			*data;
}				t_philo;

int				ft_atoi(char *nptr);
int				ft_isdigit(int c);
void			error(int n);
int				validation(int ac, char **av);
int				start_data(int ac, char **av, t_data *data);
int				start_mallocs(t_data *data);
void			start_dinner(t_data *data);
void			create_mutexes(t_data *data);
void			create_threads(t_data *data);
void			*routine(void *arg);
void			people_data(int i, t_data *data, t_philo *people);
int				take_fork(t_philo *people, int i);
int				drop_fork(t_philo *people, int i);
int				time_holder(t_philo *philo, unsigned long action);
int				food_routine(t_philo *people);
int				is_eating(t_philo *people);
int				is_sleeping(t_philo *people);
int				is_thinking(t_philo *people);
int				check_death(t_philo *people);
int				print_status(t_philo *people, char *str);
int				end_dinner(t_philo *people);
void			checker(t_data *data);
int				both_forks(t_philo *people);
int				satisfied(t_philo *people, int satisfied);
int				end_mutexes(t_data *data);
int				check_forks(t_philo *people);
void			end_threads(t_data *data, pthread_t *p);
unsigned long	get_time(void);
#endif