/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 10:24:16 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/22 10:24:17 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
long	check_args(int argc, char *argv[]);
void	tail_write(long bytes, long bufsize, long buflen, char *buf);
ssize_t	ft_read(int fd, char *buf, size_t size);

int		g_first = 1;

void	check_few(char *name, int fcnt)
{
	if (fcnt < 2)
		return ;
	if (g_first == 0)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	ft_putstr(name);
	write(1, " <==\n", 5);
	g_first = 0;
}

char	*g_name;
char	*g_arg0;

void	error(void)
{
	ft_putstr(basename(g_arg0));
	write(2, ": ", 2);
	ft_putstr(g_name);
	write(2, ": ", 2);
	ft_putstr(strerror(errno));
	write(2, "\n", 1);
}

int		tail_fd(char *name, int fcnt, int fd, long bytes)
{
	long rdc;
	long bufsize;
	long buflen;
	char *buf;
	long fsize;

	check_few(name, fcnt);
	bufsize = (bytes < 1024) ? 1024 : bytes;
	if ((buf = (char *)malloc(sizeof(char) * bufsize)) == NULL)
	{
		error();
		return (-1);
	}
	buflen = 0;
	if ((rdc = ft_read(fd, buf, bufsize)) > 0)
		buflen = rdc;
	fsize = buflen;
	while (rdc > 0)
		if ((rdc = ft_read(fd, buf, bufsize)) > 0)
			fsize += (buflen = rdc);
	tail_write((fsize < bytes) ? fsize : bytes, bufsize, buflen, buf);
	if (fd != 1)
		if (close(fd) < 0)
			error();
	return (0);
}

int		get_fd(char *name, char *arg0)
{
	int fd;

	g_name = name;
	g_arg0 = arg0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		error();
	return (fd);
}

int		main(int argc, char *argv[])
{
	int		i;
	long	bytecnt;
	int		fcnt;
	int		fd;

	bytecnt = check_args(argc, argv);
	if (bytecnt < 0)
		return (1);
	i = (ft_strcmp(argv[1], "-c") == 0) ? 3 : 2;
	fcnt = argc - i;
	if (fcnt == 0)
		if (tail_fd("", fcnt, 1, bytecnt) < 0)
			return (1);
	while (i < argc)
	{
		if ((fd = get_fd(argv[i], argv[0])) > -1)
			if (tail_fd(argv[i], fcnt, fd, bytecnt) < 0)
				return (1);
		i++;
	}
	return (0);
}
