/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:45:09 by mzary             #+#    #+#             */
/*   Updated: 2025/01/03 04:39:42 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "libft/libft.h"
# include <signal.h>

typedef struct s_byte
{
	char		byte;
	char		bit;
	int			last_cpid;
	char		utf_8[4];
	int			seq;
	int			pos;
}				t_byte;

#endif