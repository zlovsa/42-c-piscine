/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:17:41 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/09 15:17:50 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_comb2(void);

void	ft_print_2int2(int i, int j)
{
	char c;

	c = '0' + i / 10;
	write(1, &c, 1);
	c = '0' + i % 10;
	write(1, &c, 1);
	write(1, " ", 1);
	c = '0' + j / 10;
	write(1, &c, 1);
	c = '0' + j % 10;
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			if (j > 1)
				write(1, ", ", 2);
			ft_print_2int2(i, j);
			j++;
		}
		i++;
	}
}
