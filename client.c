/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:44:43 by mzary             #+#    #+#             */
/*   Updated: 2025/01/02 22:44:34 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_hold;
static void	send_byte(__pid_t server_pid, char byte);
static void	send_message(__pid_t server_pid, char *message);
static int	check_pid(char *arg, __pid_t *p_spid);
static void	permit(int sig);

int	main(int ac, char **av)
{
	__pid_t				server_pid;
	struct sigaction	sa_c;

	if (ac != 3 || check_pid(av[1], &server_pid) == -1)
		exit(EXIT_FAILURE);
	sa_c.sa_flags = 0;
	sigemptyset(&(sa_c.sa_mask));
	sa_c.sa_handler = permit;
	sigaction(SIGUSR1, &sa_c, NULL);
	g_hold = 0;
	send_message(server_pid, av[2]);
	exit(EXIT_SUCCESS);
}

static void	send_message(__pid_t server_pid, char *message)
{
	size_t	byte;

	ft_putendl_fd("[sending message to server...]", STDOUT_FILENO);
	byte = 0;
	while (message[byte])
		send_byte(server_pid, message[byte++]);
}

static void	send_byte(__pid_t server_pid, char byte)
{
	char	bits;
	int		ret;

	bits = 7;
	while (bits >= 0)
	{
		while (g_hold)
			usleep(1);
		g_hold = 1;
		if ((byte >> bits) & 1)
			ret = kill(server_pid, SIGUSR1);
		else
			ret = kill(server_pid, SIGUSR2);
		if (ret == -1)
		{
			ft_putendl_fd("[error while sending signal...]", STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
		bits--;
	}
}

static void	permit(int sig)
{
	if (sig == SIGUSR1)
		g_hold = 0;
}

static int	check_pid(char *arg, __pid_t *p_spid)
{
	char	*check;

	*p_spid = ft_atoi(arg);
	check = ft_itoa((int)*p_spid);
	if (*p_spid <= 0 || ft_strncmp(check, arg, ft_strlen(arg)) != 0)
	{
		ft_putendl_fd("[wrong format (pid)=(no space, >0)...]", STDOUT_FILENO);
		return (free(check), -1);
	}
	return (free(check), 0);
}
