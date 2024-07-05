/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:15:54 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/15 14:15:56 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_dmg(char *s, int i, int col)
{
	int d;

	d = 0;
	while (d < col)
	{
		if (*(s + d) - '0' == i ||
			*(s + d) - '0' == i + col - d ||
			*(s + d) - '0' == i + d - col)
		{
			d = -1;
			break ;
		}
		d++;
	}
	return (d);
}

int	ft_tqp_rec(char *s, int col)
{
	int i;
	int d;
	int retval;

	if (col > 9)
	{
		write(1, s, 10);
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	retval = 0;
	while (i < 10)
	{
		d = ft_check_dmg(s, i, col);
		if (d > -1)
		{
			*(s + col) = '0' + i;
			retval += ft_tqp_rec(s, col + 1);
		}
		i++;
	}
	return (retval);
}

int	ft_ten_queens_puzzle(void)
{
	char s[10];

	return (ft_tqp_rec(s, 0));
}
