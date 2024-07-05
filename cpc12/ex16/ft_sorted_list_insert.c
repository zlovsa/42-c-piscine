/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:23:04 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 12:23:05 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *b;
	t_list *n;
	t_list *prev;

	if (!begin_list)
		return ;
	b = *begin_list;
	prev = NULL;
	if ((n = ft_create_elem(data)) == NULL)
		return ;
	while (b && (*cmp)(data, b->data) > 0)
	{
		prev = b;
		b = b->next;
	}
	if (prev)
		prev->next = n;
	else
		*begin_list = n;
	n->next = b;
}
