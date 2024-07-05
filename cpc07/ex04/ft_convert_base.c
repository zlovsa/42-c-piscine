/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 08:57:26 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/18 08:57:28 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_isspace(char c);
int		check_char_in_base(char c, char *base);
int		check_base(char *base);
int		ft_cnv_len_base(long nbr, int b);

char	*ft_putnbr_base(long nbr, char *base)
{
	int		b;
	int		l;
	char	*r;

	b = check_base(base);
	if (b < 0)
		return ((void *)0);
	l = ft_cnv_len_base(nbr, b);
	if ((r = (char *)malloc(l + 1)) == (void *)0)
		return (r);
	r[l] = 0;
	if (nbr < 0)
	{
		r[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		r[l - 1] = *base;
	while (nbr > 0)
	{
		l--;
		r[l] = *(base + nbr % b);
		nbr /= b;
	}
	return (r);
}

long	ft_atoi_base(char *str, char *base)
{
	int		b;
	long	retval;
	int		sign;
	int		d;

	b = check_base(base);
	if (b < 0)
		return (0);
	retval = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (str != 0 && (d = check_char_in_base(*str, base)) > -1)
	{
		retval = retval * b + d;
		str++;
	}
	retval *= sign;
	return (retval);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long nb;
	char *r;

	if (check_base(base_from) < 0)
		return ((void *)0);
	if (check_base(base_to) < 0)
		return ((void *)0);
	nb = ft_atoi_base(nbr, base_from);
	r = ft_putnbr_base(nb, base_to);
	return (r);
}
