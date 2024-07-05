/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:11:45 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/22 14:11:47 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <stdlib.h>

void	error(char *name, char *arg0);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
int		check_args(int argc, char *argv[]);
void	ft_print_hex16(char *buf, long p, int cflag);
void	put_hex(char c, char *b);
void	final_print(char *buf, char *pbuf, size_t i, int cflag);
int		init(int argc, char *argv[], char *buf, char *pbuf);
void	init2(char *buf, int cf, int size);
char	*g_fname;
char	*g_arg0;

int		get_fd(char *name, char *arg0)
{
	int fd;

	g_fname = name;
	g_arg0 = arg0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		error(name, arg0);
		return (-1);
	}
	return (fd);
}

int		g_acnt = 0;

void	ft_print_buf(char *buf, char *pbuf, int size, int cflag)
{
	int i;

	init2(buf, cflag, size);
	i = size;
	while (i < 16)
	{
		buf[8 + cflag * 2 + i * 3 + cflag * i / 8] = ' ';
		buf[9 + cflag * 2 + i * 3 + cflag * i / 8] = ' ';
		i++;
	}
	if (ft_strcmp(buf + 7 + cflag, pbuf + 7 + cflag) == 0)
	{
		if (g_acnt > 0)
			return ;
		write(1, "*\n", 2);
		g_acnt++;
		return ;
	}
	ft_putstr(buf);
	g_acnt = 0;
	while (*buf != 0)
		*pbuf++ = *buf++;
}

char	g_cc;
int		g_fidx;
int		g_fd = -1;

void	gch3lines(void)
{
	if (g_fd > -1)
		if (close(g_fd) < 0)
			error(g_fname, g_arg0);
	g_fidx++;
}

int		getch(int argc, char *argv[], int cflag, size_t i)
{
	int rdc;

	if (argc == 1 + cflag)
	{
		if ((rdc = read(1, &g_cc, 1)) == 1)
			return (1);
		return (0);
	}
	if (g_fd > -1)
		if ((rdc = read(g_fd, &g_cc, 1)) == 1)
			return (1);
	gch3lines();
	if (g_fidx >= argc)
		return (0);
	while (g_fidx < argc && (g_fd = get_fd(argv[g_fidx], argv[0])) < 0)
		g_fidx++;
	rdc = read(g_fd, &g_cc, 1);
	if (rdc < 0 && g_fidx == argc && i == 0)
		error(g_fname, argv[0]);
	while (rdc != 1 && ++g_fidx < argc)
		if ((g_fd = get_fd(argv[g_fidx], argv[0])) > -1)
			rdc = read(g_fd, &g_cc, 1);
	if (rdc == 1)
		return (1);
	return (0);
}

int		main(int argc, char *argv[])
{
	size_t	i;
	char	pbuf[79];
	char	buf[79];
	int		cf;

	cf = init(argc, argv, buf, pbuf);
	g_fidx = cf;
	i = 0;
	while (getch(argc, argv, cf, i) > 0)
	{
		if (i > 0 && i % 16 == 0)
			ft_print_buf(buf, pbuf, 16, cf);
		if (i % 16 == 0)
			ft_print_hex16(buf, i, cf);
		if (cf == 1 && 32 <= g_cc && g_cc <= 126)
			buf[61 + i % 16] = g_cc;
		else if (cf == 1)
			buf[61 + i % 16] = '.';
		put_hex(g_cc, buf + 8 + 2 * cf + (i % 16) * 3 + cf * (i % 16) / 8);
		i++;
	}
	final_print(buf, pbuf, i, cf);
	return (0);
}
