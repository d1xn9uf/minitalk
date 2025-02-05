/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:45:09 by mzary             #+#    #+#             */
/*   Updated: 2025/01/11 23:18:28 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "utils/utils.h"
# include <signal.h>

typedef struct s_byte
{
	char		byte;
	char		bit;
	int			last_cpid;
}				t_byte;

#endif