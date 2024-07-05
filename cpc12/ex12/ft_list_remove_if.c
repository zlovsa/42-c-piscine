/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 09:32:56 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/24 09:34:03 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*free_fct)(void *))
{
	t_list *prev;
	t_list *b;
	t_list *t;

	if (begin_list == NULL)
		return ;
	prev = NULL;
	b = *begin_list;
	while (b != NULL)
	{
		t = b->next;
		if ((*cmp)(b->data, data_ref) == 0)
		{
			if (prev != NULL)
				prev->next = b->next;
			else
				*begin_list = b->next;
			(*free_fct)(b->data);
			free(b);
		}
		else
			prev = b;
		b = t;
	}
}
