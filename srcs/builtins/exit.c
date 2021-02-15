/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 02:19:20 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/15 02:33:10 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include <stdlib.h>

void	shell_exit(char **cmd)
{
	env_end();
	if (cmd[1])
		exit(ft_atoi(cmd[1]));
	else
		exit(0);
}
