/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:43:45 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/15 01:57:15 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "libft.h"
#include "builtin.h"
#include "env.h"

t_list	*g_env = 0;

char	**get_input(void)
{
	char	*line;
	char	buf[256];
	int		r;

	ft_putstr("minishell> ");
	line = ft_strdup("");
	while ((r =read(0, &buf, 256)))
	{
		buf[r] = 0;
		line = ft_strjoin(line, buf);
		if (ft_strnstr(line, "\n", ft_strlen(line)))
		{
			*ft_strnstr(line, "\n", ft_strlen(line)) = 0;
			break ;
		}
	}
	return (ft_split(line, ' '));	
}

void	run(char **cmd)
{
	char	*bin;
	char	*path;

	if (execve(cmd[0], cmd, 0) == -1)
	{
		path = env_get("PATH");
		if (path)
		{
			bin = ft_strjoin(path, cmd[0]);
			if (execve(bin, cmd, 0) == -1)
				ft_putendl("command not found");
		}
		else
			ft_putendl("command not found");
	}
}

void	env_init(void)
{
	char	buf[256];

	env_add("PATH", "/usr/bin/");
	env_add("USER", "agiraude");
	env_add("PWD", getcwd(buf, 256));
}

int		main(void)
{
	pid_t	child_pid;
	int		stat_loc;
	char	**cmd;
	int		bltin;

	env_init();

	while (1)
	{
		cmd = get_input();
		if ((bltin = is_builtin(cmd[0])) >= 0)
		{
			exec_builtin(bltin, cmd);
			continue ;
		}
		child_pid = fork();
		if (child_pid == 0)
			run(cmd);
		else
			waitpid(child_pid, &stat_loc, WUNTRACED);
		free(cmd);
	}
	return (0);
}
