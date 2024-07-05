/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:05:13 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/12 17:05:16 by mcarolee         ###   ########.fr       */
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

void	ft_putstr_non_printable(char *str)
{
	char h[3];

	h[0] = '\\';
	while (*str != 0)
	{
		if (32 <= *str && *str <= 126)
			write(1, str, 1);
		else
		{
			h[1] = ft_hexchar(*str / 16);
			h[2] = ft_hexchar(*str % 16);
			write(1, h, 3);
		}
		str++;
	}
}
