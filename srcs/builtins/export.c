/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude </var/mail/agiraude>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:44:43 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/24 11:29:36 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"

int		export_check_identifier(const char *str)
{
	while (*str)
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (0);
		srt++;
	}
	return (1);
}	

int		export_var(const char *name, const char *data)
{
	if (!export_check_identifier(name))
	{
		env_print_error("export", name);
		return (1);
	}
	elem = env_check(name);
	if (elem && *data)
	{
		free(elem->data);
		elem->data = ft_strdup(data);
	}
	else if (!elem)
		env_add(name, data);
	return (0);
}

int		export(char **cmd)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	while (cmd[i])
	{
		equal = ft_strchr(cmd[i], '=');
		if (!equal)
			ret += export_var(cmd[i], "");
		else
		{
			*equal = 0;
			ret += export_var(cmd[i], equal + 1);
		}
		i++;
	}
	if (ret > 1)
		ret = 1;
	return (ret);
}
