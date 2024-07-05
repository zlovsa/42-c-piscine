/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:28:03 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/22 19:28:06 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strcmp(char *s1, char *s2);
void	ft_print_buf(char *buf, char *pbuf, int size, int cflag);
void	ft_print_hex16(char *buf, long p, int cflag);
void	ft_putstr(char *str);

char	ft_hexchar(long h)
{
	char c;

	if (h < 10)
		c = '0' + h;
	else
		c = 'a' + h - 10;
	return (c);
}

int		check_args(int argc, char *argv[])
{
	if (argc > 1 && ft_strcmp(argv[1], "-C") == 0)
		return (1);
	return (0);
}

void	final_print(char *buf, char *pbuf, size_t i, int cflag)
{
	if (i > 0)
		ft_print_buf(buf, pbuf, (i - 1) % 16 + 1, cflag);
	if (i > 0)
	{
		ft_print_hex16(buf, i, cflag);
		buf[7 + cflag] = '\n';
		buf[8 + cflag] = 0;
		ft_putstr(buf);
	}
}

int		init(int argc, char *argv[], char *buf, char *pbuf)
{
	int		i;
	int		cflag;

	cflag = check_args(argc, argv);
	i = 0;
	while (i < 78)
		buf[i++] = ' ';
	buf[60] = '|';
	buf[78] = 0;
	pbuf[8 - cflag] = 0;
	return (cflag);
}

void	init2(char *buf, int cf, int size)
{
	if (cf == 1)
	{
		buf[61 + size] = '|';
		buf[62 + size] = '\n';
		buf[63 + size] = 0;
	}
	else
	{
		buf[55] = '\n';
		buf[56] = 0;
	}
}
