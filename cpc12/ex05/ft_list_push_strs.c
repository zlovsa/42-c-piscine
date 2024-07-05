/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:19:44 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 12:19:45 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*r;
	t_list	*n;
	int		i;

	if (strs == NULL)
		return (NULL);
	i = 0;
	r = NULL;
	while (i < size)
	{
		if ((n = ft_create_elem(strs[i])) == NULL)
			return (NULL);
		n->next = r;
		r = n;
		i++;
	}
	return (r);
}
