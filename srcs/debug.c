/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:41:55 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/15 18:42:10 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_cmd(char ***cmds)
{
	int		i;
	int		ii;

	i = 0;
	while (cmds[i])
	{
		ii = 0;
		ft_putstr("[");
		while (cmds[i][ii])
		{
			ft_putstr("\"");
			ft_putstr(cmds[i][ii]);
			ft_putstr("\"");
			if (cmds[i][ii + 1])
				ft_putstr(", ");
			ii++;
		}
		ft_putstr("]\n");
		i++;
	}
	return (0);
}
