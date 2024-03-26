#include <signal.h>
#include <unistd.h>    
#include <stdio.h>
#include "./libft/libft.h"

static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		received++;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

int	main()
{
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESART | SA_SIGINFO;
	sa.sa_handler = SIG_IGN;
	sigaction(sigint, &sa, NULL);
	while (1)
		sleep(1);
	return (0);
}
