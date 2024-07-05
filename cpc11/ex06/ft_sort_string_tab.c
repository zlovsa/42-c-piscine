/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:17:24 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 09:17:26 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_swap(char **tab, long j, long jp1)
{
	char *t;

	t = tab[j];
	tab[j] = tab[jp1];
	tab[jp1] = t;
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
				ft_swap(tab, j, j + 1);
			j++;
		}
		i++;
	}
}
