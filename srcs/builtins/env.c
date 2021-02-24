/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:57:05 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/24 10:36:08 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "env.h"

extern t_env *g_env;

/*
** The env_add function create a new element in the linked list pointed by g_env
** and set the element fields according to the given parameters.
** If the memory allocation fails, it return 0. Otherwise, it returns 1.
*/

int		env_add(char *name, char *data)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (0);
	new->name = ft_strdup(name);
	new->data = ft_strdup(data);
	new->next = g_env;
	g_env = new;
	return (1);
}

/*
** The env_check function look for an element matching the name given
** as parameter in the linked list pointed by g_env.
** If none is found, return NULL.
*/

t_env	*env_check(char *name)
{
	t_env	*elem;

	elem = g_env;
	while (elem)
	{
		if (ft_strcmp(elem->name, name) == 0)
			return (elem);
		elem = elem->next;
	}
	return (0);
}

/*
** The env_destroy function free every field of the element of type t_env and
** free the element himself.
*/

void	env_destroy(t_env *elem)
{
	free(elem->name);
	free(elem->data);
	free(elem);
}

/*
** The env_remove function look for an element in the linked list pointed by g_env.
** If it finds one, it removes it from the list, then properly destroy it.
*/

int		env_remove(char *name)
{
	t_env	*pop;
	t_env	*prev;

	if (!g_env)
		return (0);
	pop = g_env;
	prev = 0;
	while (ft_strcmp(pop->name, name) != 0)
	{
		if (!pop->next)
			break ;
		prev = pop;
		pop = pop->next;
	}
	if (prev)
		prev->next = pop->next;
	else
		g_env = pop->next;
	if (ft_strcmp(pop->name, name) == 0)
	{
		env_destroy(pop);
		return (1);
	}
	return (0);
}

/*
** The env_print function display every element in the linked list pointed by g_env,
** in the format $NAME=$VALUE.
*/

int		env_print(void)
{
	t_env	*elem;

	elem = g_env;
	while (elem)
	{
		if (ft_strcmp(elem->name, "?"))
		{
			ft_putstr(elem->name);
			ft_putstr("=");
			ft_putstr(elem->data);
			ft_putstr("\n");
		}
		elem = elem->next;
	}
	return (0);
}

/*
** The env_get function return the field "data" of the first element found in
** the linked list pointed by g_env where the field "name" match the name
** parameter. If none element match, it returns 0.
*/

char	*env_get(char *name)
{
	t_env	*elem;

	elem = env_check(name);
	if (elem)
		return (elem->data);
	return (0);
}

/* The env_unset function remove every element in the linked list pointed
** by g_env where the field "name" match one of the string in the string's
** array in cmd.
*/

int		env_unset(int argc, char **cmd)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	while (i < argc)
	{
		if (cmd[i][0] == '?')
		{
			env_print_error(cmd[0], cmd[i]);
			ret = 1;
			i++;
		}
		else
			env_remove(cmd[i++]);
	}
	return (ret);
}

/*
** The env_export fuction add to the linked list pointed by g_env an element
** in which the fields are sets accordingly to the string passed in cmd[1].
** The string must be formated as $NAME=DATA.
*/

int		env_export(char **cmd)
{
	t_env	*elem;
	char	**inputs;
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	while (cmd[i])
	{
		if (cmd[i][0] == '?')
		{
			env_print_error(cmd[0], cmd[i]);
			ret = 1;
		}
		inputs = ft_split(cmd[i], '=');
		env_replace(inputs);
		if (!inputs)
			return (1);
		if (!inputs[1])
		{
			env_print_error(cmd[0], cmd[i]);
			free(inputs);
			ret = 1;
			i++;
			continue ;
		}
		elem = env_check(inputs[0]);
		if (elem)
			elem->data = inputs[1];
		else
			env_add(inputs[0], inputs[1]);
		free(inputs);
		i++;
	}
	return (ret);
}

/*
** The env_end function properly destroy every element in the linked list
** pointed by g_env, then set g_env to NULL.
*/

void	env_end(void)
{
	t_env	*cursor;

	while (g_env)
	{
		cursor = g_env;
		g_env = g_env->next;
		env_destroy(cursor);
	}
}

/*
** The env_replace function look for string starting with '$' in the 
** null-terminated string array pass in cmd. For each match, it look if an
** element in the linked list pointed by g_env have a name identical to the
** matching string. If so, it replace the string by a copy of the data field
** of said element. Otherwise, it removes (and free) the string.
*/

void	env_replace(char **cmd)
{
	int		i;
	t_env	*elem;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i][0] == '$')
		{
			elem = env_check(cmd[i] + 1);
			if (elem)
			{
				free(cmd[i]);
				cmd[i] = ft_strdup(elem->data);
			}
			else
				free(ft_strpop(cmd, cmd[i]));
		}
		i++;
	}
}

/*
** The env_print_error function print a string with the format:
** "[cmd]: [id]: not a valid identifier\n"
*/

void	env_print_error(char *cmd, char *id)
{
	ft_putstr(cmd);
	ft_putstr(": '");
	ft_putstr(id);
	ft_putendl("': not a valid identifier");
}

/*
** The env_set_ret function look for the element in the linked list pointed
** by g_env where the field name is "?", then change its data field to an
** string compose of the number passed through ret.
*/

void	env_set_ret(int ret)
{
	t_env	*elem;

	elem = env_check("?");
	if (elem)
		elem->data = ft_itoa(ret);
}
