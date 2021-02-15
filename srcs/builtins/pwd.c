/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 02:03:09 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/15 02:13:05 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"

void	pwd(void)
{
	char	buf[1000];

	ft_bzero(buf, 1000);
	ft_putendl(getcwd(buf , 1000));
}
