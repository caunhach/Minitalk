/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caunhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:36:30 by caunhach          #+#    #+#             */
/*   Updated: 2023/07/17 16:27:42 by caunhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_printbit(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		ft_error("Invalid number of arguments");
	pid = getpid();
	ft_printf("pid : %d\n", pid);
	sa.sa_handler = &ft_printbit;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("fail to change action of SIGUSR1");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error("fail to change action of SIGUSR2");
	while (1)
		usleep(10);
	return (0);
}
