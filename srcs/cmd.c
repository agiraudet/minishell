/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:25:08 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/12 19:20:01 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_line_read(void)
{
	char	*buf;

	buf = malloc(256);

	read(1, buf, 256);
	return (buf);
}

t_cmd	cmd_line_parse(char *line)
{
	t_cmd	cmd;

	cmd.argv = ft_split(line, ' ');
	cmd.is_builtin = 1;
	return (cmd);
}

void	cmd_exec(t_cmd *cmd)
{
	return ;
}
