/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:55:32 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/02 16:55:37 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign *= -1;
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
		result = result * 10 + (*nptr++ - '0');
	return (result * sign);
}

void	send_char(pid_t pid, int c)
{
	int	bit;
	int	i;

	bit = 0;
	while (bit < 8)
	{
		i = 0;
		g_ack_received = 0;
		if (c >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack_received && i++ < 1000)
			usleep(10);
		if (i >= 1000)
		{
			message_wrong_server();
			exit(1);
		}
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*message;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	signal(SIGUSR1, ack_handler);
	signal(SIGUSR2, ack_handler);
	while (*message)
		send_char(pid, *message++);
	send_char(pid, '\n');
	message_succesfuly_sent();
	return (0);
}
