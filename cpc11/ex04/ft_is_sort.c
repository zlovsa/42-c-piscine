/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:16:38 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 09:16:39 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int cmp;
	int pcmp;

	i = 1;
	pcmp = 0;
	while (i < length)
	{
		if ((cmp = (*f)(tab[i - 1], tab[i])) != 0)
		{
			cmp = (cmp > 0) ? 1 : -1;
			if (pcmp != 0 && cmp * pcmp < 0)
				return (0);
			pcmp = cmp;
		}
		i++;
	}
	return (1);
}
