/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:45:46 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/23 18:24:49 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

	if (ac != 3)
		exit(0);
	pid = mz_pid_conv(av[1]);
	i = 0;
	while (av[2][i])
	{
		num = av[2][i];
		mz_send_binary(num, pid);
		i++;
	}
}
