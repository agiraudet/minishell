/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:01:51 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/15 02:23:29 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct		s_env
{
	char			*name;
	char			*data;
	struct s_env	*next;
}					t_env;

int			env_add(char *name, char *data);
t_env		*env_check(char *name);
void		env_destroy(t_env *elem);
int			env_remove(char *name);
void		env_print(void);
int			env_unset(int argc, char **cmd);
void		env_export(char **cmd);
char		*env_get(char *name);
void		env_end(void);

#endif
