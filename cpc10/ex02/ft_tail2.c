/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:32:27 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/22 13:32:29 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>

void	error(void);

ssize_t	ft_read(int fd, char *buf, size_t size)
{
	ssize_t rdc;

	rdc = read(fd, buf, size);
	if (rdc < 0)
		error();
	return (rdc);
}

void	tail_write(long bytes, long bufsize, long buflen, char *buf)
{
	if (bufsize == bytes)
	{
		write(1, buf + buflen, bytes - buflen);
		write(1, buf, buflen);
	}
	else
	{
		if (buflen >= bytes)
			write(1, (buf + buflen - bytes), bytes);
		else
		{
			write(1, buf, buflen);
			write(1, buf + bufsize - (bytes - buflen), bytes - buflen);
		}
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int retval;

	retval = 0;
	while (retval == 0)
	{
		retval = (unsigned char)*s1 - (unsigned char)*s2;
		if (*s1 == 0 || *s2 == 0)
			break ;
		s1++;
		s2++;
	}
	return (retval);
}

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		write(2, str, 1);
		str++;
	}
}

long	check_args(int argc, char *argv[])
{
	char *bcntstr;
	long bytecnt;

	if (argc < 2)
		return (-1);
	if (ft_strcmp(argv[1], "-c") == 0 && argc < 3)
		return (-1);
	if (argv[1][0] != '-' || argv[1][1] != 'c')
		return (-1);
	bcntstr = argv[1] + 2;
	if (ft_strcmp(argv[1], "-c") == 0)
		bcntstr = argv[2];
	bytecnt = 0;
	while (*bcntstr != 0)
	{
		if (!('0' <= *bcntstr || *bcntstr <= '9'))
			return (-1);
		bytecnt = bytecnt * 10 + *bcntstr - '0';
		bcntstr++;
	}
	return (bytecnt);
}
