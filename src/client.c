/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:36:51 by caunhach          #+#    #+#             */
/*   Updated: 2023/07/13 13:41:42 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_char_to_bit(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("fail to send message to server");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("fail to send message to server");
		}
		usleep(120);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = -1;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][++i])
			ft_char_to_bit(pid, argv[2][i]);
		ft_char_to_bit(pid, '\0');
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_char_to_bit(pid, '\0');
	return (0);
}
