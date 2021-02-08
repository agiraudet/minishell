/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:08:58 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/08 12:20:54 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_read_line(void)
{
	return (ft_strdup("test1 test2"));
}

char	**cmd_parse_line(char *cmd_line)
{
	return (ft_split(cmd_line, ' '));
}

int		cmd_is_builtin(char *cmd)
{
	return (0);
}
