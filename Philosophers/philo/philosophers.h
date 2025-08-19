/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:01:41 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/19 20:23:47 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include "catch.h"

# define GRAB 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DEAD 5

typedef struct s_philo
{
	int				philo_id;
	int				meals;
	time_t			started_eating;
	pthread_t		philo_th;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	*fork_right;
}				t_philo;

typedef struct s_context
{
	int				number_of_philosophers;
	int				number_of_times_each_philosopher_must_eat;
	int				stop;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			start_time;
	t_philo			*arr_philos;
	pthread_t		overseer;
	pthread_mutex_t	stop_lock;
	pthread_mutex_t	print_lock;
}				t_context;

/*---------- utils.c ----------*/
t_context	*context(void);

/*---------- parse_philos.c ----------*/
void		check_params(char **argv);
void		assign_value(int n, int i);
void		parse_params(char **argv);
void		init_philos(void);
void		init_context(char **argv);

/*---------- simulation.c ----------*/
int			thinking(t_philo *philo);
int			sleeping(t_philo *philo);
void		singular_philo(t_philo *philo);
void		*eat_sleep_think(void *arg);
void		run_simulation(void);

/*---------- eating.c ----------*/
int			eating_even(t_philo *philo);
int			eating_odd(t_philo *philo);
void		stop_eating(t_philo *philo);
int			eating(t_philo *philo);

/*---------- actions.c ----------*/
void		print_action(int philo_id, int action);
int			perform_action(int philo_id, int action, time_t action_time);

/*---------- stop.c ----------*/
int			check_simulation(void);
int			check_time(t_philo *philo);
int			check_meals(t_philo *philo);
int			check_philos(void);
void		*overseer(void *arg);

/*---------- clear.c ----------*/
void		clear_context(void);

/*---------- utils.c ----------*/
time_t		get_time(void);
void		sim_start_delay(time_t start_time);

/*---------- print_structs.c ----------*/
void		print_philo(const t_philo *philo);
void		print_context(const t_context *ctx);

#endif