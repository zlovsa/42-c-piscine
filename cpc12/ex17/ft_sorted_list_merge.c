/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:23:22 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 12:23:23 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1,
			t_list *begin_list2, int (*cmp)())
{
	t_list *prev;
	t_list *b1;
	t_list *t;

	if (begin_list1 == NULL)
		return ;
	b1 = *begin_list1;
	prev = NULL;
	while (begin_list2)
	{
		t = begin_list2->next;
		while (b1 && (*cmp)(begin_list2->data, b1->data) > 0)
		{
			prev = b1;
			b1 = b1->next;
		}
		if (prev)
			prev->next = begin_list2;
		else
			*begin_list1 = begin_list2;
		begin_list2->next = b1;
		prev = begin_list2;
		begin_list2 = t;
	}
}
