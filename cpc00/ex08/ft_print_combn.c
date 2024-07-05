/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:42:17 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/09 15:42:21 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_combn(int n);

void	ft_comb_plus1(char *a, int n)
{
	int j;
	int i;

	a[n - 1]++;
	j = n - 1;
	while (a[j] > 10 + j - n + '0' && j > 0)
	{
		a[j - 1]++;
		i = j;
		while (i < n)
		{
			a[i] = a[i - 1] + 1;
			i++;
		}
		j--;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	char	a[10];

	i = 0;
	while (i < n)
	{
		a[i] = i + '0';
		i++;
	}
	while (a[0] < 11 - n + '0')
	{
		if (a[n - 1] > n - 1 + '0')
			write(1, ", ", 2);
		write(1, a, n);
		ft_comb_plus1(a, n);
	}
}
