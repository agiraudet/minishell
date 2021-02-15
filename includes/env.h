/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:01:51 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/15 18:06:29 by agiraude         ###   ########.fr       */
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
int			env_print(void);
int			env_unset(int argc, char **cmd);
int			env_export(char **cmd);
char		*env_get(char *name);
void		env_end(void);
void		env_replace(char **cmd);
void		env_print_error(char *cmd, char *id);
void		env_set_ret(int ret);

#endif
