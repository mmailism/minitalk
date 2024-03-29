#include "minitalk.h"
#include <stdio.h>

// void	ft_putnbr(long nbr)
// {
// 	char	temp;

// 	if (nbr / 10 > 0)
// 		ft_putnbr(nbr / 10);
// 	temp = nbr % 10 + '0';
// 	write(1, &temp, 1);
// }

// void	sig_handle(int signal)
// {
// 	static int	i = 0;
// 	static int	j;
// 	static pid_t	client_pid = 0;
// 	int			nbr;

// 	if (signal == SIGUSR1)
// 		nbr = 0;
// 	else
// 		nbr = 1;
// 	j = (j << 1) + nbr;
// 	i++;
// 	if (i = 8)
// 	{
// 		write(1, &j, 1);
// 		i = 0;
// 		j = 0;
// 	}
// }

// // void	sig_get_pid(int signal)
// // {
// //     pid_t pid;

// //     pid = getpid();
// //     printf("Process ID (PID) : %d\n", pid);
// // }

// int	main(void)
// {
// 	struct sigaction	sa;

// 	sa.sa_handler = &sig_handle;
// 	sa.sa_flags = SA_RESTART;
// 	sigaction(SIGUSR1, &sa, NULL);
// 	sigaction(SIGUSR2, &sa, NULL);
// 	write(1, "\e[4:3mWelcome to anlima's minitalk project!\e[4:0m\n", 51);
// 	write(1, "Process ID (PID): ", 18);
// 	ft_putnbr(getpid());
// 	write(1, "\n", 1);
// 	while (1)
// 		usleep(100);
// 	return (0);
// }

static void	action(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		c = 0;
		i = 0;
	}
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		write (1, &c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	printf("Server PID = %d\n", getpid());
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		usleep(300);
	return (0);
}
