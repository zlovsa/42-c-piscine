/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 13:51:14 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/21 13:51:16 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);

int		get_fd(char *name, char *arg0)
{
	int fd;

	if (ft_strcmp(name, "-") == 0)
		return (1);
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr(basename(arg0));
		write(2, ": ", 2);
		ft_putstr(name);
		write(2, ": ", 2);
		ft_putstr(strerror(errno));
		write(2, "\n", 1);
		return (-1);
	}
	return (fd);
}

ssize_t	ft_read(int fd, char *buf, char *arg0, char *name)
{
	ssize_t rdc;

	rdc = read(fd, buf, 1024);
	if (rdc < 0)
	{
		ft_putstr(basename(arg0));
		write(2, ": ", 2);
		ft_putstr(name);
		write(2, ": ", 2);
		ft_putstr(strerror(errno));
		write(2, "\n", 1);
	}
	return (rdc);
}

void	write_fd(int fd, char *arg0, char *name)
{
	char	buf[1024];
	ssize_t	rdc;

	rdc = ft_read(fd, buf, arg0, name);
	while (rdc > 0)
	{
		write(1, &buf, rdc);
		rdc = ft_read(fd, buf, arg0, name);
	}
	if (fd != 1)
		close(fd);
}

int		main(int argc, char *argv[])
{
	int		i;
	int		fd;

	if (argc < 2)
		write_fd(1, argv[0], "");
	i = 1;
	while (i < argc)
	{
		fd = get_fd(argv[i], argv[0]);
		if (fd > -1)
			write_fd(fd, argv[i], argv[0]);
		i++;
	}
}
