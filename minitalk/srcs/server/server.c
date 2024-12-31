#include "../../include/minitalk.h"

void	test(int sig, siginfo_t *info, void *context)
{
	static int bit;
	static int res;

	(void)context;
	if (sig == SIGUSR1)
		res |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		if (res == 0)
			sig = SIGUSR2;
		else
		{
			//ft_printf("%c", res);
			sig = SIGUSR1;
		}
		res = 0;
		bit = 0;
	}
	else
		sig = SIGUSR1;
	kill(info->si_pid, SIGUSR1);
}

int main(void) 
{
    pid_t pid;
    struct sigaction sa;

    pid = getpid();
    ft_printf("%i\n", pid);
    sa.sa_sigaction = test;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL); 
    while (1) 
        pause();
    return (0);
}
