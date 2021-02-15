/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:43:45 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/15 18:06:42 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H


int		is_builtin(char *bin);
void	exec_builtin(int id, char **cmd);
int		cat(int	argc, char **argv);
int		pwd(void);
int		shell_exit(char **cmd);

#endif
