#include "minitalk.h"
#include <signal.h>
#include <asm-generic/signal-defs.h>

void	ft_server_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit = 7;
	static int	c = 0;

	(void)context;
	(void)info;
	if (signum == SIGUSR1)
	{
		c += 1 << bit;
	}
	else if (signum == SIGUSR2)
	{
		c += 0 << bit;
	}
	bit--;
	if (bit == -1)
	{
		write(1, &c, 1);
		bit = 7;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = ft_server_handler;
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sigact, NULL);
		sigaction(SIGUSR2, &sigact, NULL);
		sleep(300);
	}
}
