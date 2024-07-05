/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:58:50 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 11:58:52 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

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
		write(1, str, 1);
		str++;
	}
}

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

void	ft_putnbr(long nb)
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
	write(1, "\n", 1);
}

long	ft_atoi(char *str)
{
	long retval;
	long sign;

	retval = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		retval = retval * 10 + *str - '0';
		str++;
	}
	retval *= sign;
	return (retval);
}
