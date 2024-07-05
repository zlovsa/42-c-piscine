/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:43:21 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/10 12:45:49 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int t;

	if (size > 1)
	{
		i = 1;
		while (i < size)
		{
			j = 0;
			while (j < size - i)
			{
				if (*(tab + j) > *(tab + j + 1))
				{
					t = *(tab + j);
					*(tab + j) = *(tab + j + 1);
					*(tab + j + 1) = t;
				}
				j++;
			}
			i++;
		}
	}
}
