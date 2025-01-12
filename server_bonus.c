/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:00:14 by mzary             #+#    #+#             */
/*   Updated: 2025/01/12 03:58:31 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static t_byte	g_byte;
static void	print_server_info(void);
static void	respond(int sig, siginfo_t *info, void *context);
static void	get_sequence(void);

int	main(void)
{
	struct sigaction	sa_s;

	sa_s.sa_sigaction = respond;
	sa_s.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa_s, NULL);
	sigaction(SIGUSR2, &sa_s, NULL);
	print_server_info();
	while (1)
		pause();
}

static void	respond(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (info->si_pid != g_byte.last_cpid)
	{
		g_byte.byte = 0;
		g_byte.bit = 0;
	}
	g_byte.last_cpid = info->si_pid;
	g_byte.byte = (g_byte.byte << 1) | (sig == SIGUSR1);
	g_byte.bit += 1;
	if (g_byte.bit == 8)
	{
		if (g_byte.byte)
		{
			get_sequence();
			if (g_byte.pos == g_byte.seq)
				write(STDOUT_FILENO, g_byte.utf_8, g_byte.seq);
		}
		else if (kill(info->si_pid, SIGUSR2) == -1)
		{
			ft_putendl_fd("[error acknowledging message...]", STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
		g_byte.bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

static void	get_sequence(void)
{
	if ((unsigned char)g_byte.byte <= 0x7F)
	{
		g_byte.seq = 1;
		g_byte.utf_8[0] = g_byte.byte;
		g_byte.pos = 1;
	}
	else if ((unsigned char)g_byte.byte <= 0xBF)
	{
		g_byte.utf_8[g_byte.pos] = g_byte.byte;
		g_byte.pos += 1;
	}
	else
	{
		if ((unsigned char)g_byte.byte <= 0xDF)
			g_byte.seq = 2;
		else if ((unsigned char)g_byte.byte <= 0xEF)
			g_byte.seq = 3;
		else if ((unsigned char)g_byte.byte <= 0xF7)
			g_byte.seq = 4;
		g_byte.utf_8[0] = g_byte.byte;
		g_byte.pos = 1;
	}
}

static void	print_server_info(void)
{
	ft_putstr_fd("[server started with process id: (", STDOUT_FILENO);
	ft_putnbr_fd((int)getpid(), STDOUT_FILENO);
	ft_putendl_fd(")...]", STDOUT_FILENO);
}
