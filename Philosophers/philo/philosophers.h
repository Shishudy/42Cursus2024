/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:01:41 by rafasant          #+#    #+#             */
/*   Updated: 2025/06/13 17:25:33 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_catch
{
	char		*error_msg;
}				t_catch;

typedef struct s_philo
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	pthread_t	*arr_philos;
	time_t		start_time;
}				t_philo;

void	parse_philos(char **argv);
void	check_params(char **argv);
void	start_philos();

t_catch	*catch(void);
t_philo	*philos(void);


#endif