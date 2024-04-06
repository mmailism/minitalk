/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:30:44 by kpueankl          #+#    #+#             */
/*   Updated: 2024/04/06 14:31:00 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//funtion kill is sent a signal
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
		str = (unsigned char *)argv[2];
		while (*str)
		{
			ft_morse(pid,*str++);
		}
	}
	else
		write(1, "ERROR, INVALID ARGS\n", 20);
	return (0);
}
