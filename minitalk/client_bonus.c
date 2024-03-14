/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:22:53 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/23 20:17:56 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	mz_reply(int i)
{
	(void)i;
	write(1, "Message recieved by the server !", 32);
	exit(0);
}

static void	mz_send_binary(int num, int pid)
{
	int		i;
	int		mask;

	i = 7;
	while (i >= 0)
	{
		mask = (1 << i);
		if (num & mask)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	int		num;

	signal(SIGUSR1, mz_reply);
	signal(SIGUSR2, mz_reply);
	if (ac != 3)
		exit(0);
	pid = mz_pid_conv_bonus(av[1]);
	i = 0;
	while (av[2][i])
	{
		num = av[2][i];
		mz_send_binary(num, pid);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
	pause();
}
