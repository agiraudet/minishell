/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:56:50 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/12 19:19:51 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct	s_cmd
{
	int			is_builtin;
	char		**argv;
}				t_cmd;


char	*cmd_line_read(void);
t_cmd	cmd_line_parse(char *line);
void	cmd_exec(t_cmd *cmd);
int		builtin_run(t_cmd *cmd);
int		bi_count_arg(char **argv);
int		bi_echo(char **argv);

#endif
