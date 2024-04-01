#include "minitalk.h"

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
		usleep(100);
	}
}

// static void	action(int sig, siginfo_t *info, void *context)
// {
// 	static int				i = 0;
// 	static pid_t			client_pid = 0;
// 	static unsigned char	c = 0;

// 	(void)context;
// 	if (!client_pid)
// 		client_pid = info->si_pid;
// 	c |= (sig == SIGUSR2);
// 	if (++i == 8)
// 	{
// 		i = 0;
// 		if (!c)
// 		{
// 			kill(client_pid, SIGUSR2);
// 			client_pid = 0;
// 			return ;
// 		}
// 		ft_putchar_fd(c, 1);
// 		c = 0;
// 		kill(client_pid, SIGUSR1);
// 	}
// 	else
// 		c <<= 1;
// }

// int	main(void)
// {
// 	struct sigaction	s_sigaction;

// 	ft_putstr_fd("Server PID: ", 1);
// 	ft_putnbr_fd(getpid(), 1);
// 	ft_putchar_fd('\n', 1);
// 	s_sigaction.sa_sigaction = action;
// 	s_sigaction.sa_flags = SA_SIGINFO;
// 	sigaction(SIGUSR1, &s_sigaction, 0);
// 	sigaction(SIGUSR2, &s_sigaction, 0);
// 	while (1)
// 		usleep(300);
// 	return (0);
// }

// static void	action(int sig, siginfo_t *info, void *context)
// {
// 	static int				i = 0;
// 	static pid_t			client_pid = 0;
// 	static unsigned char	c = 0;

// 	(void)context;
// 	if (client_pid != info->si_pid)
// 	{
// 		client_pid = info->si_pid;
// 		c = 0;
// 		i = 0;
// 	}
// 	c |= (sig == SIGUSR2);
// 	if (++i == 8)
// 	{
// 		i = 0;
// 		write (1, &c, 1);
// 		c = 0;
// 	}
// 	else
// 		c <<= 1;
// }

// int	main(void)
// {
// 	struct sigaction	s_sigaction;

// 	printf("Server PID = %d\n", getpid());
// 	s_sigaction.sa_sigaction = action;
// 	s_sigaction.sa_flags = SA_SIGINFO;
// 	sigaction(SIGUSR1, &s_sigaction, 0);
// 	sigaction(SIGUSR2, &s_sigaction, 0);
// 	while (1)
// 		usleep(300);
// 	return (0);
// }
