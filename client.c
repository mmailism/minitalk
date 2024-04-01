#include "minitalk.h"
#include <stdio.h>

int	ft_morse(int pid, int c)
{
	int	bit;

	bit = 7;
	while (bit != -1)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		bit--;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int				pid;
	unsigned char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		printf("pid %s\n", argv[1]);
		str = (unsigned char *)argv[2];
		while (*str)
		{
			ft_morse(pid,*str++);
			// free(str);
		}
		// free(str);
	}
	else
	{
		write(1, "ERROR, INVALID ARGS\n", 20);
	}
	return (0);
}

// CLIENT.C file

/** global static int variable. it will help us note 
*   when we stopped receiving signals
*/

// void    send_signal(int pid, unsigned char character)
// {
//     int             i;
//     unsigned char   tmp_char;

//     i = 8;
//     tmp_char = character;
//     while(i > 0)
//     {
//         i--;
//         tmp_char = character >> i;
//         if (tmp_char % 2 = 0)
//             kill(pid, SIGUSR2);
//         else
//             kill(pid, SIGUSR1);
//         usleep(300);
//     }
// }

// void	ft_send_signal(int pid, char c)
// {
// 	int	arr[8];
// 	int	n;
// 	int	i;

// 	n = c;
// 	i = 7;
// 	while (i >= 0)
// 	{
// 		if (n == 0 || (n & 1) == 0)
// 			arr[i] = 0;
// 		else if ((n & 1) == 1)
// 			arr[i] = 1;
// 		if (n > 0)
// 			n >>= 1;
// 		i--;
// 	}
// 	while (++i < 8)
// 	{
// 		if (arr[i] == 0)
// 			kill(pid, SIGUSR1);
// 		else
// 			kill(pid, SIGUSR2);
// 		usleep(50);
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int	pid;

// 	if (argc != 3)
// 		write(1, "Args error", 10);
// 	else
// 	{
// 		pid = ft_atoi(argv[1]);
// 		while (argv[2] && *argv[2])
// 			ft_send_signal(pid, *argv[2]++);
// 		ft_send_signal(pid, '\n');
// 	}
// 	return (0);
// }

// static void	action(int sig)
// {
// 	if (sig == SIGUSR2)
// 		printf("Received sig from Server.\n");
// }

// static void	send_to_server(int pid, char *str)
// {
// 	int		i;
// 	char	c;

// 	while (*str)
// 	{
// 		i = 8;
// 		c = *str++;
// 		while (i--)
// 		{
// 			if (c >> i & 1)
// 			{
// 				if (kill(pid, SIGUSR2) == -1)
// 					exit (1);
// 			}
// 			else
// 			{
// 				if (kill(pid, SIGUSR1) == -1)
// 					exit (1);
// 			}
// 			usleep(300);
// 		}
// 	}
// 	exit (0);
// }

// int	main(int argc, char **argv)
// {
// 	int	i;

// 	i = 0;
// 	if (argc != 3 || !strlen(argv[2]))
// 		printf("Usage : ./clinet ServerPID Message.");
// 	while (argv[1][i])
// 	{
// 		if (!ft_isdigit(argv[1][i]))
// 			printf("Server PID not digit.");
// 		i++;
// 	}
// 	printf("Client PID : %d\n", getpid());
// 	signal(SIGUSR1, action);
// 	signal(SIGUSR2, action);
// 	send_to_server(ft_atoi(argv[1]), argv[2]);
// 	while (1)
// 		usleep(300);
// 	return (0);
// }
