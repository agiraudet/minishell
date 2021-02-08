/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:40:31 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/08 12:20:14 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt_print(void)
{
	printf(">");
}

int		main(int argc, char **argv)
{
	pid_t	child_pid;
	pid_t	wait_result;
	int		stat_loc;
	char	*cmd_line;
	char	**cmd;

	prompt_print();
	cmd_line = cmd_read_line();
	cmd = cmd_parse_line(cmd_line);
	if (cmd_is_builtin(*cmd))
		builtin_run(cmd);
	else
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			printf("### CHILD ###\n");
			sleep(1);
		}
		else
		{
			wait_result = waitpid(child_pid, &stat_loc, WUNTRACED);
			printf("### PARENT ###\n");
		}
	}
	
	return  (0);
}
