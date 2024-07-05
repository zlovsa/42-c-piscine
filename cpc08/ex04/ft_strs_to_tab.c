/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:08:34 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/19 15:08:37 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int l;

	l = 0;
	while (*str != 0)
	{
		str++;
		l++;
	}
	return (l);
}

char				*ft_strdup(char *src)
{
	char *rv;
	char *retval;
	long i;

	i = 0;
	while (*(src + i) != 0)
		i++;
	rv = (char *)malloc((i + 1) * sizeof(char));
	if (rv == NULL)
		return (NULL);
	retval = rv;
	while (*src != 0)
	{
		*rv = *src;
		rv++;
		src++;
	}
	*rv = 0;
	return (retval);
}

void				free_to_i(struct s_stock_str *r, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		free(r[j].copy);
		j++;
	}
	free(r);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*r;
	int					i;

	r = (struct s_stock_str *)malloc((ac + 1) * sizeof(struct s_stock_str));
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		r[i].str = av[i];
		r[i].size = ft_strlen(av[i]);
		r[i].copy = ft_strdup(av[i]);
		if (r[i].copy == NULL)
		{
			free_to_i(r, i);
			return (NULL);
		}
		i++;
	}
	r[i].str = 0;
	return (r);
}
