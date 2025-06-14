/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:01:41 by rafasant          #+#    #+#             */
/*   Updated: 2025/06/14 18:15:39 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define GRAB 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DEAD 5

typedef struct s_catch
{
	char		*error_msg;
}				t_catch;

typedef struct s_sphilo
{
	int				philo_id;
	time_t			internal_timer;
	time_t			started_eating;
	time_t			started_sleeping;
	pthread_mutex_t	fork1;
	pthread_mutex_t	*fork2;
	pthread_t		philo;
}				t_sphilo;

typedef struct s_philo
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	t_sphilo	*arr_philos;
	time_t		start_time;
}				t_philo;

void	parse_philos(char **argv);
void	check_params(char **argv);
void	start_philos();

t_catch	*catch(void);
t_philo	*philos(void);


#endif