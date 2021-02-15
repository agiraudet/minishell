/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 02:03:09 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/15 18:08:39 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"
#include <string.h>
#include <errno.h>

int		pwd(void)
{
	char	buf[1000];
	char	*path;

	ft_bzero(buf, 1000);
	path = getcwd(buf , 1000);
	if (!path)
	{
		ft_putendl(strerror(errno));
		return (1);
	}
	ft_putendl(path);
	return (0);
}
