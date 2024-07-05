/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:41:41 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/12 17:41:44 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_hexchar(char h)
{
	char c;

	if (h < 10)
		c = '0' + h;
	else
		c = 'a' + h - 10;
	return (c);
}

void	ft_put_hexchar(char h)
{
	char c;

	c = ft_hexchar(h);
	write(1, &c, 1);
}

void	ft_print_hex16(void *s)
{
	int			i;
	uintptr_t	p;
	char		buf[16];

	p = (uintptr_t)s;
	i = 16;
	while (i != 0)
	{
		buf[i - 1] = ft_hexchar(p % 16);
		p /= 16;
		i--;
	}
	write(1, buf, 16);
	write(1, ":", 1);
}

void	ft_print_buf(char *buf, int size)
{
	int i;

	i = size;
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}
	write(1, " ", 1);
	write(1, buf, size);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*s;
	unsigned int	i;
	char			buf[16];

	i = 0;
	s = (char *)addr;
	while (i < size)
	{
		if (i > 0 && i % 16 == 0)
			ft_print_buf(buf, 16);
		if (i % 16 == 0)
			ft_print_hex16(s + i);
		if (32 <= *(s + i) && *(s + i) <= 126)
			buf[i % 16] = *(s + i);
		else
			buf[i % 16] = '.';
		if (i % 2 == 0)
			write(1, " ", 1);
		ft_put_hexchar(*(s + i) / 16);
		ft_put_hexchar(*(s + i) % 16);
		i++;
	}
	if (size > 0)
		ft_print_buf(buf, (size - 1) % 16 + 1);
	return (addr);
}
