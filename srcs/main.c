/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:43:45 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/16 00:24:19 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include "libft.h"
#include "builtin.h"
#include "env.h"
#include "minishell.h"
#include "debug.h"

t_list	*g_env = 0;

void	run(char **cmd)
{
	struct stat file_def;
	char		*bin;
	char		*path;
	char		*tmp;

	path = env_get("PATH");
	bin = ft_strjoin(path, cmd[0]);
	if(stat(bin, &file_def) == 0 && (file_def.st_mode & X_OK))
	{
		execve(bin, cmd, 0);
	}
	else
	{
		ft_putstr(cmd[0]);
		ft_putendl(": command not found");
	}
	exit(0);
}

void	env_init(void)
{
	char	buf[256];

	env_add("?", "0");
	env_add("PATH", "/usr/bin/");
	env_add("USER", "agiraude");
	env_add("PWD", getcwd(buf, 256));
}

int		main(void)
{
	pid_t	child_pid;
	int		stat_loc;
	char	***cmd;
	int		bltin;
	int		i;

	env_init();

	while (1)
	{
		cmd = read_cmd();
		i = 0;
		while (cmd[i])
		{
			env_replace(cmd[i]);
			if ((bltin = is_builtin(cmd[i][0])) >= 0)
			{
				exec_builtin(bltin, cmd[i]);
			}
			else
			{
				child_pid = fork();
				if (child_pid == 0)
					run(cmd[i]);
				else
				{
					waitpid(child_pid, &stat_loc, WUNTRACED);
					env_set_ret(WEXITSTATUS(stat_loc));
				}
			}
			free(cmd[i]);
			i++;
		}
		free(cmd);
	}
	return (0);
}
