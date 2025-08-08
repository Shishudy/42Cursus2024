/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:01:41 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/08 16:28:43 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

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
	time_t			internal_timer;
	time_t			started_eating;
	time_t			started_sleeping;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	*fork_right;
	pthread_t		philo_th;
}				t_philo;

typedef struct s_context
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	t_philo		*arr_philos;
	time_t		start_time;
}				t_context;

void	parse_philos(char **argv);
void	check_params(char **argv);
void	start_philos();

t_catch		*catch(void);
t_context	*context(void);


#endif