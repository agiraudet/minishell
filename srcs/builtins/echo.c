/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:00:43 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/06 16:55:45 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		bi_count_arg(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int		bi_echo(char **argv)
{
	int		nl;
	int		i;

	i = 1;
	nl = 1;
	if (ft_strcmp(argv[i] , "-n") == 0)
	{
		nl = 0;
		i++;
	}
	while (argv[i])
	{
		printf("%s", argv[i]);
		i++;
	}
	if (nl)
		printf("\n");
	return (0);
}
