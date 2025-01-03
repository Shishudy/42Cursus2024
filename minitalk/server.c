/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:08:49 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/03 21:16:10 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*increment_new_data(char new_char, char *client_str)
{
	char	*server_str;
	size_t	len;

	len = 0;
	if (client_str)
		len = ft_strlen(client_str);
	server_str = malloc(sizeof(char) * (len + 1 + 1));
	if (server_str)
	{
		server_str = ft_memcpy(server_str, client_str, len);
		server_str[len] = new_char;
		server_str[len + 1] = '\0';
	}
	free(client_str);
	return (server_str);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int				i;
	static unsigned char	c;
	static pid_t			client_pid;
	static char				*client_str;

	(void)context;
	client_pid = info->si_pid;
	c = ((signal == SIGUSR1) << i) | c;
	i++;
	if (i == 8)
	{
		if (c)
			client_str = increment_new_data(c, client_str);
		else if (client_str)
		{
			ft_printf("%s\n", client_str);
			//kill(client_pid, SIGUSR1);
			kill(client_pid, SIGUSR2);
			free(client_str);
			client_str = NULL;
		}
		i = 0;
		c = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	ft_printf("%s", "SERVER PID: ");
	ft_printf("%d\n", pid);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &signal_handler;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
