/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:22:58 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/24 18:04:13 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n >= 0 && n <= 9)
	{
		c = n + 48;
		write(1, &c, 1);
	}
}

static void	speak(int i, siginfo_t *infos, void *context)
{
	static unsigned char	c;
	static int				shift = 7;
	static pid_t			pid;

	context = NULL;
	if (pid != infos->si_pid)
	{
		pid = infos->si_pid;
		c = 0;
		shift = 7;
	}
	if (i == SIGUSR1)
		c |= (1 << shift);
	shift--;
	if (shift < 0)
	{
		if (c == '\0')
			kill(pid, SIGUSR1);
		else
			write(1, &c, 1);
		shift = 7;
		c = 0;
	}
}

int	main(void)
{
	int					i;
	struct sigaction	sa;

	i = getpid();
	ft_putnbr(i);
	write(1, "\n", 1);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = speak;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
