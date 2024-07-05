/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:17:48 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 09:17:49 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap2(char **tab, long j, long jp1)
{
	char *t;

	t = tab[j];
	tab[j] = tab[jp1];
	tab[jp1] = t;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	long i;
	long j;
	long size;

	if (tab == (void *)0)
		return ;
	size = 0;
	while (tab[size] != (void *)0)
		size++;
	if (size < 2)
		return ;
	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
				ft_swap2(tab, j, j + 1);
			j++;
		}
		i++;
	}
}
