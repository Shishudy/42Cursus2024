/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:08:47 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/03 21:24:05 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bit_counter(int signum, siginfo_t *info, void *context)
{
	static int	bit;
	static long	size;

	(void)info;
	(void)context;
	if (signum == SIGUSR1)
	{
		bit++;
		if (bit == 8)
		{
			size++;
			bit = 0;
		}
	}
	else if (signum == SIGUSR2)
	{
		size++;
		ft_printf("\nBytes received successfully by the server: %d\n", size);
		exit(0);
	}
}

void	send_message(int pid, char *msg)
{
	int		i;
	char	byte;

	while (1)
	{
		byte = *msg;
		i = 0;
		while (i < 8)
		{
			if (byte & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			byte = (byte >> 1);
			i++;
			usleep(700);
		}
		msg++;
		if (!msg)
			break ;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*client_msg;
	struct sigaction	sig;

	if (argc != 3)
		return (ft_printf("Error: Wrong number of arguments\n"));
	pid = ft_atoi(argv[1]);
	// if (kill(pid, 0) < 0)
	// 	return (ft_printf("Error: Invalid PID\n"));
	client_msg = argv[2];
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &ft_bit_counter;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	send_message(pid, client_msg);
	return (0);
}
