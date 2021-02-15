/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:24:40 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/15 14:54:00 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
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

char	read_cmd(void)
{
	char	*cmd_line;
	char	**cmds;
	int		nb_cmd;

	cmd_line = get_input();
	cmds = ft_nsplit(cmd_line, "; ");

	int	i = 0;
	while (cmds[i])
		ft_putendl(cmds[i++]);
	return ('c');
}

int	main()
{
	read_cmd();
}
