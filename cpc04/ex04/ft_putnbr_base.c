/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:40:02 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/14 11:40:04 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_base(char *base)
{
	int		retval;
	char	*b;
	char	*c;

	retval = 0;
	b = base;
	while (*b != 0)
	{
		if (*b == '+' || *b == '-')
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

void	ft_base_rec(long nbl, int b, char *base)
{
	char c;

	if (nbl != 0)
	{
		ft_base_rec(nbl / b, b, base);
		c = *(base + nbl % b);
		write(1, &c, 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		b;
	long	nbl;

	b = check_base(base);
	if (b < 0)
		return ;
	nbl = nbr;
	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl *= -1;
	}
	if (nbl == 0)
		write(1, base, 1);
	ft_base_rec(nbl, b, base);
}
