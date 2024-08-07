/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:49:02 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/14 10:49:04 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rec(long n)
{
	char c;

	if (n != 0)
	{
		ft_rec(n / 10);
		c = '0' + n % 10;
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	long n;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n == 0)
		write(1, "0", 1);
	ft_rec(n);
}
