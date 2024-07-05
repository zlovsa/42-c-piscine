/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:22:13 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 12:22:14 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *b;

	if (begin_list1 == NULL)
		return ;
	b = *begin_list1;
	if (b == NULL)
		*begin_list1 = begin_list2;
	else
	{
		while (b->next != NULL)
			b = b->next;
		b->next = begin_list2;
	}
}
