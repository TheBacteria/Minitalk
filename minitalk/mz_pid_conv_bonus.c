/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_pid_conv_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:23:15 by mzouine           #+#    #+#             */
/*   Updated: 2024/02/24 17:02:39 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	mz_pid_conv_bonus(const char *str)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + str[i] - '0';
		else
			exit(0);
		if (nb > 4194304)
			exit(0);
		i++;
	}
	return (nb);
}
