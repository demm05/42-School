/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:52:41 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/02 16:52:41 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"
#include <signal.h>

int	process_bit(int sig)
{
	static int	bit;
	static int	res;

	if (sig == SIGUSR1)
		res |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &res, 1);
		res = 0;
		bit = 0;
		return (1);
	}
	return (0);
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static sig_atomic_t				last_pid;

	(void)context;
	if (last_pid != info->si_pid && last_pid)
	{
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	else
		last_pid = info->si_pid; 
	if (process_bit(sig))
		last_pid = 0;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	server_startup_message();
	ft_printf("%i\n", pid);
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
	return (0);
}
