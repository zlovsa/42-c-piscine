/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:50:29 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/09 14:50:35 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_comb(void);

void	ft_print_3int(int i, int j, int k)
{
	char c;

	c = '0' + i;
	write(1, &c, 1);
	c = '0' + j;
	write(1, &c, 1);
	c = '0' + k;
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < 8)
	{
		j = i + 1;
		while (j < 9)
		{
			k = j + 1;
			while (k < 10)
			{
				if (k > 2)
					write(1, ", ", 2);
				ft_print_3int(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
