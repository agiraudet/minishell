/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:37:50 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/15 02:29:58 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtin.h"
#include "env.h"

int		is_builtin(char *bin)
{
	if (ft_strncmp(bin, "cat", 3) == 0)
		return (0);
	if (ft_strncmp(bin, "env", 3) == 0)
		return (1);
	if (ft_strncmp(bin, "export", 6) == 0)
		return (2);
	if (ft_strncmp(bin, "unset", 5) == 0)
		return (3);
	if (ft_strcmp(bin, "pwd") == 0)
		return (4);
	if (ft_strcmp(bin, "exit") == 0)
		return (5);
	return (-1);
}

void	exec_builtin(int id, char **cmd)
{
	int		argc;

	argc = 0;
	while (cmd[argc])
		argc++;
	if (id == 0)
		cat(argc, cmd);
	if (id == 1)
		env_print();
	if (id == 2)
		env_export(cmd);
	if (id == 3)
		env_unset(argc, cmd);
	if (id == 4)
		pwd();
	if (id == 5)
		shell_exit(cmd);
}
