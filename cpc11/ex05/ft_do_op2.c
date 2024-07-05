/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:58:42 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 11:58:44 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

void	ft_plus(long l, long r)
{
	ft_putnbr(l + r);
}

void	ft_minus(long l, long r)
{
	ft_putnbr(l - r);
}

void	ft_mul(long l, long r)
{
	ft_putnbr(l * r);
}

void	ft_div(long l, long r)
{
	if (r == 0)
		ft_putstr("Stop : division by zero\n");
	else
		ft_putnbr(l / r);
}

void	ft_mod(long l, long r)
{
	if (r == 0)
		ft_putstr("Stop : modulo by zero\n");
	else
		ft_putnbr(l % r);
}
