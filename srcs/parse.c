/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:24:40 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/15 18:41:50 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "env.h"
#define BUF_SIZE 256

void	display_prompt(void)
{
	ft_putstr("minishell> ");
}

char	*get_input(void)
{
	char	*line;
	char	*tmp;
	char	buf[BUF_SIZE];
	int		rd;
	int		nl;

	display_prompt();
	line = ft_strdup("");
	while ((rd = read(0, &buf, BUF_SIZE)))
	{
		buf[rd] = 0;
		tmp = line;
		line = ft_strjoin(line, buf);
		nl = ft_getindex(line, '\n');
		if (nl != -1)
		{
			line[nl] = 0;
			break ;
		}
	}
	free(tmp);
	return (line);
}

char	***read_cmd(void)
{
	char	*line;
	char	**cmd_line;
	char	***cmds;
	int		i;

	line = get_input();
	cmd_line = ft_split(line, ';');

	i = 0;
	while (cmd_line[i])
		i++;
	if (!(cmds = malloc(sizeof(char**) * (i + 1))))
		return (0);
	i = 0;
	while (cmd_line[i])
	{
		cmds[i] = ft_split(cmd_line[i], ' ');
		free(cmd_line[i]);
		i++;
	}
	cmds[i] = 0;
	return (cmds);
}
