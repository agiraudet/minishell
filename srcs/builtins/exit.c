/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 02:19:20 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/16 00:25:21 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include <stdlib.h>

int		shell_exit(char **cmd)
{
	env_end();
	if (cmd[1])
		exit(ft_atoi(cmd[1]));
	else
		exit(0);
}
