/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 08:57:34 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/18 08:57:36 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isspace(char c)
{
	int retval;

	retval = 0;
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		retval = 1;
	return (retval);
}

int	check_char_in_base(char c, char *base)
{
	int retval;

	retval = 0;
	while (c != *(base + retval) && *(base + retval) != 0)
		retval++;
	if (*(base + retval) == 0)
		return (-1);
	else
		return (retval);
}

int	ft_cnv_len_base(long nbr, int b)
{
	int l;

	l = 0;
	if (nbr < 0)
	{
		l++;
		nbr *= -1;
	}
	if (nbr == 0)
		l++;
	while (nbr > 0)
	{
		l++;
		nbr /= b;
	}
	return (l);
}

int	check_base(char *base)
{
	int		retval;
	char	*b;
	char	*c;

	retval = 0;
	b = base;
	while (*b != 0)
	{
		if (*b == '+' || *b == '-' || ft_isspace(*b))
			return (-1);
		c = base;
		while (c != b)
		{
			if (*c == *b)
				return (-1);
			c++;
		}
		retval++;
		b++;
	}
	if (retval < 2)
		return (-1);
	return (retval);
}
