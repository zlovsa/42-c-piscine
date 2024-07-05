/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:28:13 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/22 19:28:15 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include <libgen.h>
#include <string.h>

char	ft_hexchar(long h);

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

void	error(char *name, char *arg0)
{
	ft_putstr(basename(arg0));
	write(2, ": ", 2);
	ft_putstr(name);
	write(2, ": ", 2);
	ft_putstr(strerror(errno));
	write(2, "\n", 1);
}

void	put_hex(char c, char *b)
{
	*b = ft_hexchar((unsigned char)c / 16);
	*(b + 1) = ft_hexchar((unsigned char)c % 16);
}

void	ft_print_hex16(char *buf, long p, int cflag)
{
	int			i;

	i = 7 + cflag;
	while (i != 0)
	{
		buf[i - 1] = ft_hexchar(p % 16);
		p /= 16;
		i--;
	}
}
