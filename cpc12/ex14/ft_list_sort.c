/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:22:31 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 12:22:32 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_sort_swap(t_list *prev, t_list *bj, t_list **begin_list)
{
	t_list *t;
	t_list *bjp1;

	bjp1 = bj->next;
	t = bjp1->next;
	if (prev)
		prev->next = bjp1;
	else
		*begin_list = bjp1;
	bjp1->next = bj;
	bj->next = t;
	return (bjp1);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *bi;
	t_list *bj;
	t_list *prev;

	if (begin_list == NULL)
		return ;
	bi = *begin_list;
	if (bi == NULL)
		return ;
	prev = NULL;
	while (bi->next)
	{
		bj = bi;
		while (bj->next)
		{
			if ((*cmp)(bj->data, bj->next->data) > 0)
				bj = ft_list_sort_swap(prev, bj, begin_list);
			prev = bj;
			bj = bj->next;
		}
		bi = bi->next;
	}
}
