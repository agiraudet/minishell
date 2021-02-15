/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:10:28 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/15 17:30:38 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	print_error(char *arg0, char *argi)
{
	ft_putstr_fd(arg0, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(argi, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

void	read_stdin(void)
{
	char	buf[256];
	int		rd;

	while ((rd = read(0, buf, 255)))
	{
		buf[rd] = 0;
		ft_putstr_fd(buf, 1);
	}
}

void	read_file(char *file)
{
	char	buf[256];
	int		fd;
	int		rd;

	fd = open(file, O_RDONLY);
	while ((rd = read(fd, buf, 255)))
	{
		buf[rd] = 0;
		ft_putstr_fd(buf, 1);
	}
	close(fd);
}

int		file_allowed(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY | O_DIRECTORY);
	if (fd != -1)
	{
		errno = 21;
		close(fd);
		return (0);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	if (close(fd) == -1)
		return (0);
	return (1);
}

int		cat(int	argc, char **argv)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	if (argc == 1)
		read_stdin();
	if (argc >= 2)
		while (i < argc)
		{
			if (argv[i][0] == '-' && !argv[i][1])
				read_stdin();
			else if (!file_allowed(argv[1]))
			{
				print_error(argv[0], argv[i]);
				ret = 1;
			}
			else
				read_file(argv[i]);
			i++;
		}
	return (ret);
}
